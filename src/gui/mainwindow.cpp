#include "mainwindow.h"
#include "dialogstring.h"
#include "ui_mainwindow.h"
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
    QObject::connect(ui->saveSession, SIGNAL(triggered(bool)), this, SLOT(saveSession()));
    QObject::connect(ui->loadSession, SIGNAL(triggered(bool)), this, SLOT(loadSession()));
    QObject::connect(ui->showHelp, SIGNAL(triggered(bool)), this, SLOT(showHelp()));
    QObject::connect(ui->tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
    QObject::connect(ui->saveGraph, SIGNAL(triggered(bool)), this, SLOT(saveTab()));
    QObject::connect(ui->loadGraph, SIGNAL(triggered(bool)), this, SLOT(loadTab()));
    QObject::connect(ui->closeGraph, SIGNAL(triggered(bool)), this, SLOT(closeCurrent()));

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

void MainWindow::saveSession() {
    QString fname = QFileDialog::getSaveFileName(this, QString("Save session"), QString(), QString("Graphy session (*.ghy))"));
    if(fname.isEmpty()) {
        return;
    }

    QFile file(fname);
    file.open(QIODevice::WriteOnly);

    QByteArray qba("");

    int nbrOfWidget = ui->tabWidget->count();

    qba.append(QString::number(nbrOfWidget)+"\n");

    for(int i = 0; i < nbrOfWidget; i++) {
        qba.append(((Console*)ui->tabWidget->widget(i))->prepareDataForSave());
    }

    file.write(qba);

    file.close();
}

void MainWindow::loadSession() {
    QString fname = QFileDialog::getOpenFileName(this, QString("Load session"), QString(), QString("Graphy session (*.ghy)"));
    if(fname.isEmpty()) {
        return;
    }

    QFile file(fname);
    file.open(QIODevice::ReadOnly);

    QByteArray qba = file.readAll();

    //qba = QByteArray::fromHex(qba);





    file.close();
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
    if(ui->tabWidget->count() > 0) {
        ((Console*)ui->tabWidget->currentWidget())->save();
        //temp->saveChanges();
    }
}

void MainWindow::loadTab()
{
    if(ui->tabWidget->count() > 0)
    {
        ((Console*)ui->tabWidget->currentWidget())->load();
    }
}

void MainWindow::closeTab(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::closeCurrent()
{
    ui->tabWidget->removeTab(ui->tabWidget->currentIndex());
}

void MainWindow::showHelp() {
    helpWindow = HelpWindow::getInstance(
                                this,
                                new QString("../userHelp/pages/"));
    helpWindow->show();
}

void MainWindow::getTabName(QString& name) {
    name = ui->tabWidget->tabToolTip(ui->tabWidget->currentIndex());
}

void MainWindow::setTabName(const QString& name) {
    ui->tabWidget->setTabText(ui->tabWidget->currentIndex(), name);
}
