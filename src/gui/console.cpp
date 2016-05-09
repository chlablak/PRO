#include "console.h"
#include <iostream>

/*
 *
 */

Console::Console() : Console("") {}

Console::Console(const QString& s, QWidget *parent) : prompt(s), cursor(textCursor()) {
    cursorPosition = 0;
    insertPlainText(prompt + " > ");

    if(parent != 0) {
        QObject::connect(this, SIGNAL(signalChanges()), parent, SLOT(consoleHasChanged()));
        QObject::connect(this, SIGNAL(signalSave()), parent, SLOT(saveConsole()));
    }

}

void Console::keyPressEvent(QKeyEvent *event) {
    if(!isReadOnly())
    {
        if( event->key() == Qt::Key_Escape)
        {
            if(currentCommand != commandHistory.end())
            {
                clearDisplay();
                currentCommand = commandHistory.end();
            }
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

            std::cout << buffer.toStdString() << std::endl;
            commandHistory.insert(commandHistory.begin(), buffer);
            currentCommand = commandHistory.end();

            //execute(buffer);

            insertPlainText("\n" + prompt + " > ");
            cursor.movePosition(QTextCursor::End);
            cursorPosition = 0;
            buffer = "";
            consoleHasChanged();
        }
        else if( event->key() == Qt::Key_S && event->modifiers() & Qt::ControlModifier)
        {
            if(hasChanged)
            {
                saveChanges();
            }
        }
        else
        {
            if(currentCommand != commandHistory.end())
                currentCommand = commandHistory.end();
            setTextCursor(cursor);
            insertPlainText(event->text());
            buffer.insert(cursorPosition, QLatin1String(event->text().toLatin1()));
            cursorPosition++;
            if(event->text() != "")
            {
                consoleHasChanged();
            }
        }
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

void Console::saveChanges()
{
    hasChanged = false;
    emit signalSave();
}
