#include "mainwindow.h"
#include "dialogstring.h"
#include "ui_mainwindow.h"
#include "userHelp/helpwindow.h"
#include "userHelp/mainbrowser.h"
#include <iostream>
#include <QTextEdit>

#include <QFileDialog>


#include <QApplication>

#include "console.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->setMovable(true);
    ui->tabWidget->setStyleSheet("QTabBar::tab{width:100px;}");

    QObject::connect(ui->newGraph, SIGNAL(triggered(bool)), this, SLOT(newGraph()));
    QObject::connect(ui->loadSession, SIGNAL(triggered(bool)), this, SLOT(loadSession()));
    QObject::connect(ui->showHelp, SIGNAL(triggered(bool)), this, SLOT(showHelp()));
    QObject::connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
    QObject::connect(ui->saveGraph, SIGNAL(triggered(bool)), this, SLOT(saveTab()));
    QObject::connect(ui->loadGraph, SIGNAL(triggered(bool)), this, SLOT(loadTab()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newGraph()
{
    dialogString* d = new dialogString(this, "Enter a name", "Validate");
    d->setModal(true);
    d->show();
    QObject::connect(d, SIGNAL(sendValue(const QString)), this, SLOT(newTab(const QString)));
}

void MainWindow::newTab(const QString& name)
{
    QString graphName = name;
    ui->tabWidget->addTab(new Console("", this), graphName);
    ui->tabWidget->setTabToolTip(ui->tabWidget->count()-1,name);
}

void MainWindow::loadSession() {
    QString stringaMoi = QFileDialog::getOpenFileName();
    cout << stringaMoi.toStdString() << endl;
}

void MainWindow::consoleHasChanged()
{
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), ui->tabWidget->tabText(ui->tabWidget->currentIndex())+ "*");
}

void MainWindow::saveConsole()
{
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), ui->tabWidget->tabText(ui->tabWidget->currentIndex()).left(ui->tabWidget->tabText(ui->tabWidget->currentIndex()).size()-1));
}

void MainWindow::saveTab()
{
    if(ui->tabWidget->count() > 0)
    {
        ((Console*)ui->tabWidget->currentWidget())->save();
        //temp->saveChanges();
    }
}

void MainWindow::loadTab() {
    ((Console*)ui->tabWidget->currentWidget())->load();
}

void MainWindow::closeTab(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::showHelp() {
    //QApplication app(argc, argv);
    QWidget *window = new QWidget();
    window->setMinimumSize(800,600);
    window->setStyleSheet("background-color:white");

    window->setWindowTitle(QApplication::translate("toplevel", "User guide"));

    //RightPane *layout = RightPane::getInstance(window);
    HelpWindow *layout = HelpWindow::getInstance(window, new QString("../gui/userHelp/pages/"));
    window->setLayout(layout);
    window->show();

    //app.exec();
}

void MainWindow::getTabName(QString& name) {
    name = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
}

void MainWindow::setTabName(const QString& name) {
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), name);
}
