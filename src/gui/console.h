#ifndef CONSOLE_H
#define CONSOLE_H


#include <QTextEdit>
#include <QKeyEvent>
#include <QLinkedList>

class Console : public QTextEdit
{
    Q_OBJECT
public:
    Console();
    Console(const QString&, QWidget *parent = 0);
    void saveChanges();

protected:
    void keyPressEvent(QKeyEvent*);

private:
    QString buffer;
    size_t cursorPosition;
    QTextCursor cursor;
    QString prompt;
    QLinkedList<QString> commandHistory;
    QLinkedList<QString>::iterator currentCommand;
    bool hasChanged;

    void clearDisplay();

    void consoleHasChanged();

signals:
    void signalChanges();
    void signalSave();
};

#endif // CONSOLE_H
