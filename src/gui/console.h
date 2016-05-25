#ifndef CONSOLE_H
#define CONSOLE_H


#include <QTextEdit>
#include <QKeyEvent>
#include <QLinkedList>
#include <QByteArray>
#include <QCompleter>
#include <QCompleter>
#include <QStringList>
#include <QAbstractItemView>
#include <QApplication>
#include <QModelIndex>
#include <QScrollBar>
#include <QtAlgorithms>
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

    /*!
     * \brief updates the list of words for auto completion
     * \param l: list of words
     */
    void updateCompleterList();

    /*!
     * \brief returns if s1 < s2 (case insensitive
     * \param s1
     * \param s2
     * \return bool
     */
    static bool caseInsensitiveLessThan(const QString &s1, const QString &s2);

protected:
    /*!
     * \brief processes the raw keyboard input
     * \param e: keyEvent
     */
    void keyPressEvent(QKeyEvent *e);

    /*!
     * \brief redefined to focus on the completer when needed
     * \param e: focusEvent
     */
    void focusInEvent(QFocusEvent *e);

private:
    QString buffer;    
    QString prompt;
    QLinkedList<QString> commandHistory;
    QLinkedList<QString>::iterator currentCommand;
    QString filename;

    static egli::Interpreter interpreter;
    static bool interfaced;
    egli::Data dataState;

    void execute(const QString& buffer);


    bool hasChanged;
    size_t cursorPosition;
    QTextCursor cursor;
    const QString fileDelimiter = "°§§°";

    void clearDisplay();
    void consoleHasChanged();

    static bool drawGraph(const IGraph* graph);
    static bool exportSvg_1(const IGraph* graph);
    static bool exportSvg_2(const IGraph* graph, const string& filename);
    static Console* currentConsole;

    /*!
     * \brief gets the current word under cursor
     * \return word under cursor
     */
    QString textUnderCursor() const;

    /*! \brief Custom keyboard input processing for console use
     */
    void processKeyboardInput(QKeyEvent *e);

    QCompleter *completer;
    QStringList *completerWordList;

signals:
    void signalChanges();
    void signalSave();
    void askTabName(QString&);
    void requestTabNameChanges(const QString&);
    void requestTabChange(int shift);

public slots:
    void copySelectedText();
    void pasteText();
    void save();
    void load();

private slots:
    /*! \brief Inserts the end of selected word to cursor position
     */
    void insertCompletion(const QString &completion);
};

#endif // CONSOLE_H
