#ifndef CONSOLE_H
#define CONSOLE_H


#include <QTextEdit>
#include <QKeyEvent>
#include <QLinkedList>
#include <QByteArray>
#include <QCompleter>
#include <QAbstractItemModel>
#include "../egli/egli.h"

class Console : public QTextEdit
{
    Q_OBJECT
public:
    Console();
    Console(const QString&, QWidget *parent = 0);
    void saveChanges();

    QByteArray prepareDataForSave();
    void loadDataToConsole(QByteArray& data, bool ignoreFilename = true);

    void setCompleter(QCompleter *completer);
    QCompleter* completer() const;

protected:
    void keyPressEvent(QKeyEvent* event);
    void focusInEvent(QFocusEvent* event);

private:
    QString buffer;    
    QString prompt;
    QLinkedList<QString> commandHistory;
    QLinkedList<QString>::iterator currentCommand;
    QString filename;

    const QString fileDelimiter = "°§§°";

    static egli::Interpreter interpreter;
    static bool interfaced;
    egli::Data dataState;

    void execute(const QString& buffer);


    bool hasChanged;
    size_t cursorPosition;
    QTextCursor cursor;

    QCompleter *c;

    void clearDisplay();

    void consoleHasChanged();

    QString textUnderCursor() const;

    static bool drawGraph(const IGraph* graph);
    static Console* currentConsole;

signals:
    void signalChanges();
    void signalSave();
    void askTabName(QString&);
    void requestTabNameChanges(const QString&);

public slots:
    void copySelectedText();
    void pasteText();
    void save();
    void load();

private slots:
    void insertCompletion(const QString& completion);
};

#endif // CONSOLE_H
