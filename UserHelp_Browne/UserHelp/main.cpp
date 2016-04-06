#include <QApplication>
#include <QWidget>
#include <QTextDocument>
#include <QLabel>
#include <QLayout>
#include <QTextEdit>
#include <QPushButton>
#include <QTextCursor>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget *window = new QWidget();
    //window->resize(600,400);
    window->setMinimumSize(600,400);
    //window->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
    window->setStyleSheet("background-color:white");

    window->setWindowTitle(QApplication::translate("toplevel", "User guide"));

    QWidget *leftMenu = new QWidget();//window);

    QPushButton *btn = new QPushButton(QApplication::translate("childwidget", "my btn"), leftMenu);
    btn->show();

    QTextEdit *mainHelp = new QTextEdit();//window);

    mainHelp->setReadOnly(true);
    mainHelp->setText(" <a href=\"http://www.w3schools.com\">Visit W3Schools</a> ");
    mainHelp->show();

    QTextCursor *cursor = new QTextCursor(mainHelp->textCursor());

    QHBoxLayout *layout = new QHBoxLayout();
    //layout->addWidget(leftMenu);
    layout->addWidget(btn);
    layout->addWidget(mainHelp);

    window->setLayout(layout);
    window->show();

    return app.exec();
}
