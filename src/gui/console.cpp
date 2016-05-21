#include "console.h"
#include <iostream>
#include <QMenu>
#include <QApplication>
#include <QClipboard>
#include <QFileDialog>
#include "graphwindow.h"


#include "../visualization/GraphWidget.h"
#include "../visualization/GraphExporter.h"

#include "../graph/Includes.h"

/*
 *
 */

Console::Console() : Console("") {}

Console::Console(const QString& s, QWidget *parent) : prompt(s), cursor(textCursor()) {
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

}

void Console::keyPressEvent(QKeyEvent *event) {
    if(!isReadOnly())
    {
        if(event->matches(QKeySequence::Cut))
            event->ignore();

        if( event->key() == Qt::Key_Escape)
        {
            Vertex *v1 = new Vertex("Vertex 1");
            Vertex *v2 = new Vertex("Vertex 2");
            Vertex *v3 = new Vertex("Vertex 3");
            Vertex *v4 = new Vertex("Vertex 4");

            IEdge *e1 = new Edge(v1, v2, "Edge 1", 3.2);
            IEdge *e2 = new Edge(v1, v4, "Edge 2", 1.0);
            IEdge *e3 = new Edge(v4, v2, "Edge 1", 5.0);

            vector<Vertex *> vectices = { v1, v2, v3, v4 };
            vector<IEdge *> edges = { e1, e2, e3 };

            IGraph *graph = new Graph(vectices, edges);


            GraphWindow *g = new GraphWindow(this, graph);

            g->show();

/*
            dialogString* d = new dialogString(this, "Enter a name", "Validate");
            d->setModal(true);
            d->show();*/


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
            //commandHistory.insert(commandHistory.begin(), buffer);
            commandHistory.push_front(buffer);
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
                save();
            }
        }
        else if( event->modifiers() & Qt::ControlModifier || event->modifiers() & Qt::AltModifier)
        {
            //Ne rien faire
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

QString Console::getFilename()const
{
    return filename;
}

void Console::setFilename(const QString& name)
{
    filename = name;
}

QByteArray Console::prepareDataForSave() {
    QByteArray qba("");

    QString tabName = "";

    emit askTabName(tabName);

    qba.append(tabName+"\n");
    qba.append(filename+"\n");
    qba.append(prompt+"\n");
    qba.append(buffer+"\n");
    qba.append(QString(QString::number(commandHistory.size()))+"\n");
    for(auto c: commandHistory) {
        qba.append(c+fileDelimiter+"\n");
    }

    qba.append(QString(QString::number(toPlainText().count("\n")+1)+"\n"));

    qba.append(toPlainText());

    return qba;
}

void Console::save() {
    if(filename == "")
    {
        QFileDialog dialog;
        QString fname = QFileDialog::getSaveFileName(this, QString("Save console"), QString(), QString("Graph (*.gph)"));
        if(fname.isEmpty()) {
            return;
        }
        filename = fname;
    }

    QFile file(filename);
    file.open(QIODevice::WriteOnly);

    QByteArray qba = prepareDataForSave();

    file.write(qba);

    file.close();

    emit signalSave();
    hasChanged = false;
}

void Console::load() {
    commandHistory.clear();
    selectAll();
    clear();
    std::cout << "coucou" << std::endl;
    QFileDialog dialog;
    QString fname = QFileDialog::getOpenFileName(this, QString("Save console"), QString(), QString("Graph (*.gph)"));
    if(fname.isEmpty()) {
        return;
    }
    filename = fname;


    QFile file(filename);
    file.open(QIODevice::ReadOnly);

    char data[1024];

    int size = file.readLine(data, 1023);
    data[size-1] = '\0';
    emit requestTabNameChanges(QString(data));

    //Lecture du nom de fichier pour s'en débarasser
    file.readLine(data, 1023);

    size = file.readLine(data, 1023);
    data[size-1] = '\0';
    prompt = QString(data);

    size = file.readLine(data, 1023);
    data[size-1] = '\0';
    buffer = QString(data);

    size = file.readLine(data, 1023);
    data[size-1] = '\0';
    int nbrOfCommand = atoi(data);

    commandHistory.clear();

    for(int i = 0; i < nbrOfCommand;) {
        size = file.readLine(data, 1023);

        QString line = QString(data);


        if(line.contains(QString(fileDelimiter+"\n")))
            i++;

        commandHistory.push_back(line.replace(QString(fileDelimiter+"\n"), QString("\0")));
    }
    currentCommand = commandHistory.end();

    size = file.readLine(data, 1023);
    data[size-1] = '\0';
    int nbrLine = atoi(data);

    for(int i = 0; i < nbrLine; i++) {
        size = file.readLine(data, 1023);
        data[size-1] = '\0';
        append(QString(data));
    }


    file.close();
}
