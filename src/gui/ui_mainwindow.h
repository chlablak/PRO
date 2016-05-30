/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *loadSession;
    QAction *saveSession;
    QAction *actionSave_all;
    QAction *newGraph;
    QAction *loadGraph;
    QAction *closeGraph;
    QAction *closeAllGraphs;
    QAction *saveGraph;
    QAction *saveAllGraphs;
    QAction *actionExit;
    QAction *showHelp;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuGraph;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral("favicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDocumentMode(false);
        MainWindow->setDockNestingEnabled(true);
        loadSession = new QAction(MainWindow);
        loadSession->setObjectName(QStringLiteral("loadSession"));
        saveSession = new QAction(MainWindow);
        saveSession->setObjectName(QStringLiteral("saveSession"));
        actionSave_all = new QAction(MainWindow);
        actionSave_all->setObjectName(QStringLiteral("actionSave_all"));
        newGraph = new QAction(MainWindow);
        newGraph->setObjectName(QStringLiteral("newGraph"));
        newGraph->setCheckable(false);
        loadGraph = new QAction(MainWindow);
        loadGraph->setObjectName(QStringLiteral("loadGraph"));
        closeGraph = new QAction(MainWindow);
        closeGraph->setObjectName(QStringLiteral("closeGraph"));
        closeAllGraphs = new QAction(MainWindow);
        closeAllGraphs->setObjectName(QStringLiteral("closeAllGraphs"));
        saveGraph = new QAction(MainWindow);
        saveGraph->setObjectName(QStringLiteral("saveGraph"));
        saveAllGraphs = new QAction(MainWindow);
        saveAllGraphs->setObjectName(QStringLiteral("saveAllGraphs"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        showHelp = new QAction(MainWindow);
        showHelp->setObjectName(QStringLiteral("showHelp"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuGraph = new QMenu(menuBar);
        menuGraph->setObjectName(QStringLiteral("menuGraph"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuGraph->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(saveSession);
        menuFile->addAction(loadSession);
        menuEdit->addAction(actionExit);
        menuGraph->addAction(newGraph);
        menuGraph->addAction(loadGraph);
        menuGraph->addSeparator();
        menuGraph->addAction(saveGraph);
        menuGraph->addAction(saveAllGraphs);
        menuGraph->addSeparator();
        menuGraph->addAction(closeGraph);
        menuGraph->addAction(closeAllGraphs);
        menuHelp->addAction(showHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GraphY", 0));
        loadSession->setText(QApplication::translate("MainWindow", "Load", 0));
        loadSession->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+L", 0));
        saveSession->setText(QApplication::translate("MainWindow", "Save", 0));
        saveSession->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0));
        actionSave_all->setText(QApplication::translate("MainWindow", "Save all", 0));
        newGraph->setText(QApplication::translate("MainWindow", "New", 0));
        newGraph->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        loadGraph->setText(QApplication::translate("MainWindow", "Load", 0));
        loadGraph->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0));
        closeGraph->setText(QApplication::translate("MainWindow", "Close", 0));
        closeGraph->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        closeAllGraphs->setText(QApplication::translate("MainWindow", "Close All", 0));
        saveGraph->setText(QApplication::translate("MainWindow", "Save", 0));
        saveGraph->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        saveAllGraphs->setText(QApplication::translate("MainWindow", "Save All", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        showHelp->setText(QApplication::translate("MainWindow", "Show help", 0));
        showHelp->setShortcut(QApplication::translate("MainWindow", "F1", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "Session", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuGraph->setTitle(QApplication::translate("MainWindow", "Graph", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
