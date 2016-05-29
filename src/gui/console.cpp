/*! \brief Implementation of a console re-implementing QTextEdit
 *
 * \file console.cpp
 * \author Alain Hardy
 * \date 30.04.2016
 */

#include <QMenu>
#include <QApplication>
#include <QClipboard>
#include <QFileDialog>
#include <QBuffer>
#include <QCompleter>
#include <QAbstractItemView>
#include <QScrollBar>
#include <QMessageBox>
#include "graphwindow.h"
#include "console.h"
#include "../visualization/GraphWidget.h"
#include "../visualization/GraphExporter.h"
#include "../graph/Includes.h"
#include "../utility/Timer.h"

/*
 *
 */

egli::Interpreter Console::interpreter;
bool Console::interfaced = false;
Console* Console::currentConsole = nullptr;

Console::Console() : Console("") {}


Console::Console(const QString& prompt, QWidget *parent) : prompt(prompt),
                                                      cursor(textCursor()),
                                                      completer(nullptr),
                                                      completerWordList(nullptr)
{
    cursorPosition = 0;
    insertPlainText(prompt + " > ");
    setAcceptDrops(false);
    setFont(QFont("Courier New", 9));

    filename = "";

    if(parent != 0) {
        QObject::connect(this, SIGNAL(signalChanges()), parent, SLOT(consoleHasChanged()));
        QObject::connect(this, SIGNAL(signalSave()), parent, SLOT(saveConsole()));
        QObject::connect(this, SIGNAL(askTabName(QString&)), parent, SLOT(getTabName(QString&)));
        QObject::connect(this, SIGNAL(requestTabNameChanges(const QString&)), parent, SLOT(setTabName(const QString&)));
        QObject::connect(this, SIGNAL(requestTabChange(int)), parent, SLOT(changeTab(int)));
    }

    if (!interfaced) {
        interpreter.functions().interface("draw", drawGraph);
        interpreter.functions().interface("exportAsSvg", exportSvg_1);
        interpreter.functions().interface("exportAsSvg", exportSvg_2);
        interfaced = true;
    }

    updateCompleterList();
}

void Console::processKeyboardInput(QKeyEvent *event)
{
    if(!isReadOnly()) {

        if(event->matches(QKeySequence::Cut))
            event->ignore();

        if( event->key() == Qt::Key_Escape) {
            clearCommand();
            currentCommand = commandHistory.end();
        }
        else if( event->key() == Qt::Key_Up) {
            if(commandHistory.size() > 0 && currentCommand != --(commandHistory.end())) {
                clearCommand();

                if(currentCommand == commandHistory.end()) {
                    currentCommand = commandHistory.begin();
                    buffer = *currentCommand;
                }
                else {
                    buffer = *(++currentCommand);
                }

                setTextCursor(cursor);
                insertPlainText(buffer);

                cursorPosition = buffer.size();
            }
        }
        else if( event->key() == Qt::Key_Down) {
            if(commandHistory.size() > 0 && currentCommand != commandHistory.begin() && currentCommand != commandHistory.end()) {
                clearCommand();

                setTextCursor(cursor);
                buffer = *(--currentCommand);

                insertPlainText(buffer);
                cursorPosition = buffer.size();
            }
        }
        else if( event->key() == Qt::Key_Left) {
            if ( cursorPosition > 0) {
                cursor.movePosition(QTextCursor::Left);
                setTextCursor(cursor);
                --cursorPosition;
            }
        }
        else if( event->key() == Qt::Key_Right) {
            if ( cursorPosition < buffer.size()) {
                cursor.movePosition(QTextCursor::Right);
                setTextCursor(cursor);
                ++cursorPosition;
            }
        }
        else if( event->key() == Qt::Key_Backspace) {
            if ( cursorPosition > 0) {
                setTextCursor(cursor);
                buffer.remove(cursorPosition-1, 1);
                cursorPosition--;
                cursor.deletePreviousChar();
                consoleHasChanged();
            }
        }
        else if( event->key() == Qt::Key_Delete) {
            if( cursorPosition < buffer.size()) {
                setTextCursor(cursor);
                buffer.remove(cursorPosition, 1);
                cursor.deleteChar();
                consoleHasChanged();
            }
        }
        else if( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
            moveCursor(QTextCursor::End);

            commandHistory.push_front(buffer);
            currentCommand = commandHistory.end();

            execute(buffer);

            insertPlainText("\n" + prompt + " > ");
            cursor.movePosition(QTextCursor::End);
            cursorPosition = 0;
            buffer = "";
            consoleHasChanged();
            ensureCursorVisible();
        }
        else if( event->key() == Qt::Key_Tab && event->modifiers() & Qt::ControlModifier) {
            emit requestTabChange(1);
        }
        else if( event->key() == Qt::Key_Backtab && event->modifiers() & Qt::ControlModifier) {
            emit requestTabChange(-1);
        }
        else {
            if(event->text() != "") {
                if(currentCommand != commandHistory.end())
                    currentCommand = commandHistory.end();
                setTextCursor(cursor);
                insertPlainText(event->text());
                buffer.insert(cursorPosition, QLatin1String(event->text().toLatin1()));
                cursorPosition++;

                consoleHasChanged();
            }
        }
    }
}

void Console::execute(const QString &buffer)
{
    currentConsole = this;
    interpreter.setData(&dataState);
    interpreter.writer() << buffer.toStdString();
    while(interpreter.available()) {
        try {
            utility::Timer timer;
            egli::Statement statement = interpreter.next();
            double time = timer.elapsed();
            insertPlainText("\n Elapsed time : " + QString::number(time) + "s");
            if(dataState.variables().exists(statement.value)) {
                int nbrOfCharToDisplay = 100;
                QString resToDisplay = QString::fromStdString(statement.value+" = "+dataState.variables().toString(statement.value));
                insertPlainText(" -> " +resToDisplay.left(nbrOfCharToDisplay));
                if(resToDisplay.size() > nbrOfCharToDisplay)
                    insertPlainText(" ...");

            }

        } catch(const std::runtime_error& e) {
            insertPlainText("\n => "+QString(e.what()));
        }
        ensureCursorVisible();
    }
    updateCompleterList();
}

void Console::save()
{
    if(hasChanged) {
        saveConsole();
    }
}

void Console::clearCommand()
{
    cursor.movePosition(QTextCursor::End);
    cursor.movePosition(QTextCursor::Left, QTextCursor::KeepAnchor, buffer.size());
    cursor.removeSelectedText();
    cursorPosition = 0;
    buffer = "";
}

void Console::consoleHasChanged()
{
    if(!hasChanged)
    {
        hasChanged = true;
        emit signalChanges();
    }
}

void Console::copySelectedText() {
    copy();
}

void Console::pasteText()
{
    if(!QApplication::clipboard()->text().contains("§") && !QApplication::clipboard()->text().contains("°")) {
        setTextCursor(cursor);
        buffer.insert(cursorPosition, QApplication::clipboard()->text());
        paste();
    }
}

void QTextEdit::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu *menu = new QMenu();
    menu->addAction("Copy", this, SLOT(copySelectedText()), QKeySequence("Ctrl+C"));
    menu->addAction("Paste", this, SLOT(pasteText()), QKeySequence("Ctrl+V"));
    menu->addAction("Select All", this, SLOT(selectAll()), QKeySequence("Ctrl+A"));
    menu->exec(event->globalPos());
    delete menu;
}

void Console::saveConsole()
{
    if(!hasChanged)
        return;
    QString fname = filename;
    if(filename == "")
    {
        QFileDialog dialog;
        fname = QFileDialog::getSaveFileName(this, QString("Save graph"), QString(), QString("Graph (*.gph)"));
        if(fname.isEmpty()) {
            return;
        }
        filename = fname;
    }

    QFile file(fname);
    file.open(QIODevice::WriteOnly);

    hasChanged = false;
    emit signalSave();

    QByteArray qba = prepareDataForSave();

    qba.prepend("GRAPH\n");
    file.write(qba.toHex());

    file.close();
}

QByteArray Console::prepareDataForSave()
{
    QByteArray qba("");

    QString tabName = "";

    emit askTabName(tabName);

    if(tabName.endsWith("*") && hasChanged) {
        tabName = tabName.left(tabName.size()-1);
    }

    qba.append(tabName+"\n");
    qba.append(filename+"\n");
    qba.append(prompt+"\n");
    qba.append(buffer+"\n");
    qba.append(QString::number(commandHistory.size())+"\n");
    for(auto c: commandHistory) {
        qba.append(c+fileDelimiter+"\n");
    }

    qba.append(QString(QString::number(toPlainText().count("\n")+1)+"\n"));

    qba.append(toPlainText()+"\n");
    qba.append(QString::fromStdString(egli::serialize(dataState)+"\n"));

    return qba;
}

void Console::loadConsole()
{
    QString fname = QFileDialog::getOpenFileName(this, QString("Load graph"), QString(), QString("Graph (*.gph)"));
    if(fname.isEmpty()) {
        return;
    }

    QFile file(fname);
    file.open(QIODevice::ReadOnly);

    QByteArray qba = file.readAll();
    qba = QByteArray::fromHex(qba);
    QBuffer dataBuffer(&qba);
    dataBuffer.open(QIODevice::ReadOnly);

    char charArray[10];
    int size = dataBuffer.readLine(charArray, 9);
    charArray[size-1] = '\0';
    if(!(strcmp(charArray, "GRAPH") == 0)) {
        QMessageBox::warning(this, "Error loading file", "The format of the file is not correct");
        file.close();
        return;
    }

    filename = fname;

    qba = dataBuffer.readAll();

    loadDataToConsole(qba, true);

    file.close();
}


void Console::loadDataToConsole(QByteArray& data, bool ignoreFilename)
{
    commandHistory.clear();
    selectAll();
    clear();

    QBuffer dataBuffer(&data);
    dataBuffer.open(QIODevice::ReadOnly);

    char charArray[1024];

    int size = dataBuffer.readLine(charArray, 1023);
    charArray[size-1] = '\0';
    emit requestTabNameChanges(QString(charArray));

    //Lecture du nom de fichier pour s'en débarasser
    size = dataBuffer.readLine(charArray, 1023);
    if(!ignoreFilename) {
        charArray[size-1] = '\0';
        filename = QString(charArray);
    }

    size = dataBuffer.readLine(charArray, 1023);
    charArray[size-1] = '\0';
    prompt = QString(charArray);

    size = dataBuffer.readLine(charArray, 1023);
    charArray[size-1] = '\0';
    buffer = QString(charArray);

    size = dataBuffer.readLine(charArray, 1023);
    charArray[size-1] = '\0';
    int nbrOfCommand = atoi(charArray);

    for(int i = 0; i < nbrOfCommand;) {
        size = dataBuffer.readLine(charArray, 1023);

        QString line = QString(charArray);


        if(line.contains(QString(fileDelimiter+"\n")))
            i++;

        commandHistory.push_back(line.replace(QString(fileDelimiter+"\n"), QString("\0")));
    }
    currentCommand = commandHistory.end();

    size = dataBuffer.readLine(charArray, 1023);
    charArray[size-1] = '\0';
    int nbrLine = atoi(charArray);

    for(int i = 0; i < nbrLine; i++) {
        size = dataBuffer.readLine(charArray, 1023);
        charArray[size-1] = '\0';
        append(QString(charArray));
    }

    QString temp = "";
    bool continuteToLoop = false;

    do {
        size = dataBuffer.readLine(charArray, 1023);
        char charNewLine[] = "\n";
        continuteToLoop = (strpbrk(charArray, charNewLine) == 0);
        if(!continuteToLoop)
            charArray[size-1] = '\0';
        temp.append(charArray);
    }while(continuteToLoop);


    egli::deserialize(interpreter, dataState, temp.toStdString());


    cursorPosition = buffer.size();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);
    hasChanged = false;

    dataBuffer.close();
}

bool Console::drawGraph(const IGraph* graph)
{
    GraphWindow *g = new GraphWindow(currentConsole, graph, QString());
    g->show();
    return true;
}

bool Console::exportSvg_1(const IGraph* graph)
{
    GraphExporter::SVG(graph);
    return true;
}

bool Console::exportSvg_2(const IGraph* graph, const string& filename)
{
    GraphExporter::SVG(graph, QString::fromStdString(filename));
    return true;
}

void Console::insertCompletion(const QString &completion)
{
    if (completer == nullptr) {
        return;
    }

    int extra = completion.length() - completer->completionPrefix().length();
    cursor.insertText(completion.right(extra));
    buffer.insert(cursorPosition, completion.right(extra));

    cursorPosition += extra;

    if (completion.endsWith("()")) {
       cursor.movePosition(QTextCursor::Left);
       cursorPosition--;
    }

    setTextCursor(cursor);
}

QString Console::textUnderCursor() const
{
    QTextCursor tc = textCursor();
    tc.movePosition(QTextCursor::Left);
    tc.select(QTextCursor::WordUnderCursor);

    //control characters
    if (tc.selectedText() == QString(">") || tc.selectedText().startsWith("()"))
        return QString("");

    return tc.selectedText();
}

void Console::focusInEvent(QFocusEvent *e)
{
    if (completer)
        completer->setWidget(this);
    QTextEdit::focusInEvent(e);
}

bool Console::caseInsensitiveLessThan(const QString &s1, const QString &s2)
{
    return s1.toLower() < s2.toLower();
}

void Console::updateCompleterList()
{
    QStringList varList;

    for (std::string s : dataState.variables().find("")) {
        QString tmp(s.c_str());
        if(!varList.contains(tmp)) {
            varList << tmp;
        }
    }

    qSort(varList.begin(), varList.end(),
          Console::caseInsensitiveLessThan);

    QStringList functionList;
    for (std::string s : interpreter.functions().find("")) {
        QString tmp(s.c_str());
        tmp.append("()");
        if (!tmp.startsWith("__") && !functionList.contains(tmp)) {
            functionList << tmp;
        }
    }

    qSort(functionList.begin(), functionList.end(),
          Console::caseInsensitiveLessThan);


    completerWordList = new QStringList(varList + functionList);

    if (completer)
        QObject::disconnect(completer, 0, this, 0);

    completer = new QCompleter(*completerWordList);
    completer->setWidget(this);
    completer->setCompletionMode(QCompleter::PopupCompletion);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    QObject::connect(completer, SIGNAL(activated(QString)),
                     this, SLOT(insertCompletion(QString)));

}

void Console::keyPressEvent(QKeyEvent *e)
{
    if (completer && completer->popup()->isVisible()) {
        switch (e->key()) {
            case Qt::Key_Enter:
            case Qt::Key_Return:
            case Qt::Key_Escape:
            case Qt::Key_Tab:
            case Qt::Key_Backtab:
                e->ignore();
                return;
            default:
                break;
        }
    }

    bool isShortcut = ((e->modifiers() & Qt::ControlModifier) &&
                        e->key() == Qt::Key_Space);

    if (!completer || !isShortcut)
        processKeyboardInput(e);

    bool ctrlOrShift = e->modifiers() &
                       (Qt::ControlModifier | Qt::ShiftModifier);

    if (!completer || (ctrlOrShift && e->text().isEmpty()))
        return;

    static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-="); // end of word

    bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
    QString completionPrefix = textUnderCursor();

    if (!isShortcut && (hasModifier || e->text().isEmpty()||
                        completionPrefix.length() == 0 ||
                        eow.contains(e->text().right(1)))) {
        completer->popup()->hide();
        return;
    }

    if (completionPrefix != completer->completionPrefix()) {
        completer->setCompletionPrefix(completionPrefix);
        completer->popup()->
                 setCurrentIndex(completer->completionModel()->index(0, 0));
    }

    QRect cr = cursorRect();
    cr.setWidth(completer->popup()->sizeHintForColumn(0)
                + completer->popup()->verticalScrollBar()->sizeHint().width());
    completer->complete(cr);
}
