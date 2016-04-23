#include <QApplication>
#include <QWidget>
#include <QTextDocument>
#include <QLabel>
#include <QLayout>
#include <QTextEdit>
#include <QTextStream>
#include <QPushButton>
#include <QTextCursor>

#include "helpbrowser.h"
#include "helpwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget();
    window->setMinimumSize(600,400);
    window->setStyleSheet("background-color:white");

    window->setWindowTitle(QApplication::translate("toplevel", "Guide utilisateur"));

    HelpWindow *layout = HelpWindow::getInstance(window);
    window->setLayout(layout);
    window->show();

    return app.exec();
}
