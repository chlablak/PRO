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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void newGraph();
    void loadSession();
    void showHelp();
    void newTab(const QString&);
    void saveTab();
    void loadTab();
    void closeTab(int index);
    void consoleHasChanged();
    void saveConsole();
    void getTabName(QString&);
    void setTabName(const QString&);
private:
    Ui::MainWindow *ui;
    HelpWindow *helpWindow;

protected:
    void keyPressEvent(QKeyEvent *e);
};

#endif // MAINWINDOW_H
