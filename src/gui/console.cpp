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

Console::Console(const QString& s, QWidget *parent) : prompt(s), cursor(textCursor()), c(0), QTextEdit(parent){
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

    c = new QCompleter(parent);
    setCompleter(c);

    if (!interfaced) {
        interpreter.functions().interface("draw", drawGraph);
        interfaced = true;
    }
}

void Console::keyPressEvent(QKeyEvent *event) {
    if(!isReadOnly())
    {
        if(c && c->popup()->isVisible())
        {
            switch(event->key())
            {
            case Qt::Key_Enter:
            case Qt::Key_Return:
            case Qt::Key_Escape:
            case Qt::Key_Tab:
            case Qt::Key_Backtab:
                event->ignore();
                return;
            default:
                break;
            }
        }

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
        else if( event->key() == Qt::Key_Space && event->modifiers() & Qt::ControlModifier)
        {
            std::cout << "Code completion" << std::endl;

            QRect cr = cursorRect();
            std::cout << cr.left() << " " << cr.top() << std::endl;
            cr.setWidth(c->popup()->sizeHintForColumn(0) + c->popup()->verticalScrollBar()->sizeHint().width());
            std::cout << cr.width() << std::endl;
            c->complete(cr);
            std::cout << c->popup()->pos().x() << " " << c->popup()->pos().y() << std::endl;
        }
        /*else if( event->modifiers() & Qt::ControlModifier || event->modifiers() & Qt::AltModifier)
        {
            event->ignore();
        }*/
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



//COMPLETER=============================================================
void Console::setCompleter(QCompleter *completer)
{
    if(c)
    {
        QObject::disconnect(c, 0, this, 0);
    }

    c = completer;

    if(!c)
    {
        return;
    }

    c->setWidget(this);
    c->setCompletionMode(QCompleter::PopupCompletion);
    c->setCaseSensitivity(Qt::CaseInsensitive);
    QObject::connect(c, SIGNAL(activated(QString)), this, SLOT(insertCompletion(QString)));
}

QCompleter* Console::completer() const
{
    return c;
}

void Console::insertCompletion(const QString& completion)
{
    if(c->widget() != this)
    {
        return;
    }

    int extra = completion.length() - c->completionPrefix().length();

    QTextCursor tc = textCursor();

    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);
    tc.insertText(completion.right(extra));
    setTextCursor(tc);


    /*
    cursor.movePosition(QTextCursor::Left);
    cursor.movePosition(QTextCursor::EndOfWord);
    cursor.insertText(completion.right(extra));

    setTextCursor(cursor);
    //*/

    buffer.insert(cursorPosition, completion.right(extra));
    cursorPosition += extra;
}

QString Console::textUnderCursor() const
{
    QTextCursor tc = cursor;
    tc.select(QTextCursor::WordUnderCursor);
    return tc.selectedText();
}

void Console::focusInEvent(QFocusEvent* event)
{
    if(c)
    {
        c->setWidget(this);
    }
    QTextEdit::focusInEvent(event);
}
