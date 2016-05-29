/*! \brief Implementation of a console re-implementing QTextEdit
 *
 * \file console.h
 * \author Alain Hardy
 * \date 30.04.2016
 */

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
    /*!
     * \brief Default constructor
     */
    Console();

    /*!
     * \brief Construct a console
     * \param prompt: Specify the value which be displayed in the prompt
     * \param parent: MainWindow considered as a parent. It is not recommanded to
     * use another type of widget.
     */
    Console(const QString& prompt, QWidget *parent = 0);

    /*!
     * \brief saveChanges
     */
    void saveChanges();

    /*!
     * \brief Prepare and store data of the console into a QByteArray
     * \return A QByteArray containing the data of the console.
     */
    QByteArray prepareDataForSave();

    /*!
     * \brief loadDataToConsole
     * \param data: QByteArray containing the data to use to restore the console
     * \param ignoreFilename: Ignore the name of the file when reading the data-
     */
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
    /*!
     * \brief Contains the current text
     */
    QString buffer;    
    QString prompt;
    QLinkedList<QString> commandHistory;
    QLinkedList<QString>::iterator currentCommand;
    QString filename;

    static egli::Interpreter interpreter;
    static bool interfaced;
    egli::Data dataState;

    /*!
     * \brief Execute
     * \param buffer
     */
    void execute(const QString& buffer);


    bool hasChanged;
    size_t cursorPosition;
    QTextCursor cursor;

    /*!
     * \brief Use to separate commands in console file.
     */
    const QString commandDelimiter = "°§§°";

    /*!
     * \brief Clear the command type by the user
     */
    void clearCommand();

    /*!
     * \brief Fonction that emit a signal that the console has changed,
     * if the console was not already in "has changed" state.
     */
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

    /*!
     * \brief Save the console if it has changed
     */
    void save();

signals:
    /*!
     * \brief Signal changes to parent to make it change the tab
     */
    void signalChanges();

    /*!
     * \brief Signal save to parent to make it change the tab
     */
    void signalSave();

    /*!
     * \brief Ask the parent what is the name of the tab bar
     */
    void askTabName(QString&);

    /*!
     * \brief Ask the parent to change the name of the tab bar
     */
    void requestTabNameChanges(const QString&);

    /*!
     * \brief Ask the parent to change the current tab based on the shift
     * \param shift: A minus value indicate a shift to the left while a plus value a shift to the right
     */
    void requestTabChange(int shift);

public slots:
    /*!
     * \brief Copy the selected text to the clipboard
     */
    void copySelectedText();

    /*!
     * \brief Paste text from the clipboard into the console
     */
    void pasteText();

    /*!
     * \brief Save console's data into a file
     */
    void saveConsole();

    /*!
     * \brief Load console's data from a file
     */
    void loadConsole();

private slots:
    /*! \brief Inserts the end of selected word to cursor position
     */
    void insertCompletion(const QString &completion);
};

#endif // CONSOLE_H
