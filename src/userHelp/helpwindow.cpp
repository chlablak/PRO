#include "helpwindow.h"

HelpWindow *HelpWindow::instance = nullptr;
QString *HelpWindow::_baseUrl = nullptr;

HelpWindow::HelpWindow(QWidget *parent) : parent(parent)
{
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    setMinimumSize(800,600);
    setStyleSheet("background-color:white");
    setWindowTitle("User Guide");
    setLayout(HelpMainLayout::getInstance(parent, _baseUrl));
    show();
}

HelpWindow *HelpWindow::getInstance(QWidget *parent, QString *baseUrl)
{
    if (instance == nullptr) {
        _baseUrl = baseUrl;
        instance = new HelpWindow(parent);
    }
    return instance;
}


