#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>

#include "helpmainlayout.h"

class HelpWindow : public QDialog
{
private:
    HelpWindow(QWidget *parent);

    static HelpWindow *instance;
    static QString *_baseUrl;

    QWidget *parent;

public:
    static HelpWindow *getInstance(QWidget *parent, QString *baseUrl);


};

#endif // HELPWINDOW_H
