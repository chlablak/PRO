/*! \brief Main window of the application
 *
 * \file mainwindow.h
 * \author Alain Hardy
 * \date 19.05.2016
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../userHelp/helpwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Constructor
     * \param parent: parent of the window
     */
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    /*!
     * \brief Open a window to let the user input the name of the tab
     *  and once its is done, it will initiate the creation of the console
     */
    void newConsole();

    /*!
     * \brief Save all the tabs into a session file
     */
    void saveSession();

    /*!
     * \brief Restore tabs from a session file
     */
    void loadSession();

    /*!
     * \brief Display the help window
     */
    void showHelp();

    /*!
     * \brief Create a new tab
     */
    void newTab(const QString&);

    /*!
     * \brief Call the save fonctioon of the console within the current tab.
     */
    void saveTab();

    /*!
     * \brief Call the load fonction of the console within the current tab.
     */
    void loadTab();

    /*!
     * \brief Close the tab at a given index
     * \param index: index of the tab to close
     */
    void closeTab(int index);

    /*!
     * \brief Change the current tab to the next one
     * \param direction: positive value change to the right and negative to the left
     */
    void changeTab(int direction);

    /*!
     * \brief Close the current tab
     */
    void closeCurrent();

    /*!
     * \brief Called when changes occur to the console in the current tab
     */
    void consoleHasChanged();

    /*!
     * \brief Called when the console in the current tab is saved
     */
    void saveConsole();

    /*!
     * \brief Used by a console to get the name of the tab that contains it
     */
    void getTabName(QString&);

    /*!
     * \brief Change the name of the tab containing the console
     */
    void setTabName(const QString&);

    /*!
     * \brief Close the main window
     */
    void closeWindow();
private:
    Ui::MainWindow *ui;
    HelpWindow *helpWindow;


    /*!
     * \brief Used to separate console's data in a session file
     */
    const QString graphDelimiter = "§§§§°°";
};

#endif // MAINWINDOW_H
