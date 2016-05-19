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

    QString getFilename()const;
    void setFilename(const QString& name);

protected:
    void keyPressEvent(QKeyEvent*);

private:
    QString buffer;    
    QString prompt;
    QLinkedList<QString> commandHistory;
    QLinkedList<QString>::iterator currentCommand;
    QString filename;

    bool hasChanged;
    size_t cursorPosition;
    QTextCursor cursor;

    void clearDisplay();

    void consoleHasChanged();

    QByteArray prepareDataForSave();


    const QString fileDelimiter = "°§§°";

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
};

#endif // CONSOLE_H
