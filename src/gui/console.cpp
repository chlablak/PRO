#include <iostream>
#include <QMenu>
#include <QApplication>
#include <QClipboard>
#include <QFileDialog>
#include <QBuffer>
#include <QCompleter>
#include <QAbstractItemView>
#include <QScrollBar>


#include "graphwindow.h"
#include "console.h"
#include "../visualization/GraphWidget.h"
#include "../visualization/GraphExporter.h"

#include "../graph/Includes.h"

/*
 *
 */

egli::Interpreter Console::interpreter;
bool Console::interfaced = false;
Console* Console::currentConsole = nullptr;

Console::Console() : Console("") {}


Console::Console(const QString& s, QWidget *parent) : prompt(s),
                                                      cursor(textCursor()),
                                                      completer(nullptr),
                                                      completerWordList(nullptr)
{
    cursorPosition = 0;
    insertPlainText(prompt + " > ");
    setAcceptDrops(false);

    filename = "";

    if(parent != 0) {
        QObject::connect(this, SIGNAL(signalChanges()), parent, SLOT(consoleHasChanged()));
        QObject::connect(this, SIGNAL(signalSave()), parent, SLOT(saveConsole()));
        QObject::connect(this, SIGNAL(askTabName(QString&)), parent, SLOT(getTabName(QString&)));
        QObject::connect(this, SIGNAL(requestTabNameChanges(const QString&)), parent, SLOT(setTabName(const QString&)));
    }

    if (!interfaced) {
        interpreter.functions().interface("draw", drawGraph);
        interfaced = true;
    }
}

void Console::processKeyboardInput(QKeyEvent *event)
{
    if(!isReadOnly())
    {

        if(event->matches(QKeySequence::Cut))
            event->ignore();

        if( event->key() == Qt::Key_Escape)
        {
            clearDisplay();
            currentCommand = commandHistory.end();
        }
        else if( event->key() == Qt::Key_Up)
        {
            if(commandHistory.size() > 0 && currentCommand != --(commandHistory.end()))
            {
                clearDisplay();

                if(currentCommand == commandHistory.end())
                {
                    currentCommand = commandHistory.begin();
                    buffer = *currentCommand;
                }
                else
                {
                    buffer = *(++currentCommand);
                }

                setTextCursor(cursor);
                insertPlainText(buffer);

                cursorPosition = buffer.size();
            }
        }
        else if( event->key() == Qt::Key_Down)
        {
            if(commandHistory.size() > 0 && currentCommand != commandHistory.begin() && currentCommand != commandHistory.end())
            {
                clearDisplay();

                setTextCursor(cursor);
                buffer = *(--currentCommand);

                insertPlainText(buffer);
                cursorPosition = buffer.size();
            }
        }
        else if( event->key() == Qt::Key_Left)
        {
            if ( cursorPosition > 0)
            {
                cursor.movePosition(QTextCursor::Left);
                setTextCursor(cursor);
                --cursorPosition;
            }
        }
        else if( event->key() == Qt::Key_Right)
        {
            if ( cursorPosition < buffer.size())
            {
                cursor.movePosition(QTextCursor::Right);
                setTextCursor(cursor);
                ++cursorPosition;
            }
        }
        else if( event->key() == Qt::Key_Backspace)
        {
            if ( cursorPosition > 0)
            {
                setTextCursor(cursor);
                buffer.remove(cursorPosition-1, 1);
                cursorPosition--;
                cursor.deletePreviousChar();
                consoleHasChanged();
            }
        }
        else if( event->key() == Qt::Key_Delete)
        {
            if( cursorPosition < buffer.size())
            {
                setTextCursor(cursor);
                buffer.remove(cursorPosition, 1);
                cursor.deleteChar();
                consoleHasChanged();
            }
        }
        else if( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        {
            moveCursor(QTextCursor::End);

            commandHistory.push_front(buffer);
            currentCommand = commandHistory.end();

            std::cout << buffer.toStdString() << std::endl;


            execute(buffer);

            insertPlainText("\n" + prompt + " > ");
            cursor.movePosition(QTextCursor::End);
            cursorPosition = 0;
            buffer = "";
            consoleHasChanged();
            ensureCursorVisible();
        }
        else if( event->key() == Qt::Key_S && event->modifiers() & Qt::ControlModifier)
        {
            if(hasChanged)
            {
                save();
            }
        }
        else
        {
            if(event->text() != "")
            {
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
            egli::Statement statement = interpreter.next();
            insertPlainText("\n => "+QString::fromStdString(statement.value+" = "+dataState.variables().toString(statement.value)));

        } catch(const std::runtime_error& e) {
            insertPlainText("\n => "+QString(e.what()));
        }
        ensureCursorVisible();
    }
}

void Console::clearDisplay()
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

void Console::pasteText() {
    if(!QApplication::clipboard()->text().contains("§") && !QApplication::clipboard()->text().contains("°"))
    {
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

void Console::save() {
    if(filename == "")
    {
        QFileDialog dialog;
        QString fname = QFileDialog::getSaveFileName(this, QString("Save graph"), QString(), QString("Graph (*.gph)"));
        if(fname.isEmpty()) {
            return;
        }
        filename = fname;
    }

    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QByteArray qba = prepareDataForSave();

    file.write(qba.toHex());

    file.close();

    emit signalSave();
    hasChanged = false;
}

QByteArray Console::prepareDataForSave() {
    QByteArray qba("");

    QString tabName = "";

    emit askTabName(tabName);

    qba.append(tabName+"\n");
    qba.append(filename+"\n");
    qba.append(prompt+"\n");
    qba.append(QString::number(commandHistory.size())+"\n");
    for(auto c: commandHistory) {
        qba.append(c+fileDelimiter+"\n");
    }

    return qba;
}

void Console::load() {
    commandHistory.clear();
    selectAll();
    clear();

    QString fname = QFileDialog::getOpenFileName(this, QString("Load graph"), QString(), QString("Graph (*.gph)"));
    if(fname.isEmpty()) {
        return;
    }
    filename = fname;

    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    QByteArray qba = file.readAll();

    qba = QByteArray::fromHex(qba);

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
    int nbrOfCommand = atoi(charArray);

    for(int i = 0; i < nbrOfCommand;) {
        size = dataBuffer.readLine(charArray, 1023);

        QString line = QString(charArray);


        if(line.contains(QString(fileDelimiter+"\n")))
            i++;

        commandHistory.push_back(line.replace(QString(fileDelimiter+"\n"), QString("\0")));
    }
    currentCommand = commandHistory.end();

    cursorPosition = buffer.size();
    cursor.movePosition(QTextCursor::End);
    setTextCursor(cursor);

    dataBuffer.close();
}

bool Console::drawGraph(const IGraph* graph)
{
    GraphWindow *g = new GraphWindow(currentConsole, graph, QString());
    g->show();
    return true;
}

void Console::insertCompletion(const QString &completion)
{
    if (completer == nullptr) {
        return;
    }
    QTextCursor tc = textCursor();
    int extra = completion.length() - completer->completionPrefix().length();
    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);
    tc.insertText(completion.right(extra));
    setTextCursor(tc);
}

QString Console::textUnderCursor() const
{
    QTextCursor tc = textCursor();
    tc.select(QTextCursor::WordUnderCursor);
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

void Console::setCompleterList(QStringList l)
{
    qSort(l.begin(), l.end(), Console::caseInsensitiveLessThan);

    completerWordList = new QStringList(l);

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
                        completionPrefix.length() < 3 ||
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
