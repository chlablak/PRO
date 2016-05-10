#ifndef DIALOGSTRING_H
#define DIALOGSTRING_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class dialogString;
}

class dialogString : public QDialog
{
    Q_OBJECT

public:
    explicit dialogString(QWidget *parent = 0, QString title = "New", QString buttonName = "Ok");
    ~dialogString();

signals:
    void sendValue(const QString);

private slots:
    void on_validateButton_clicked();

private:
    Ui::dialogString *ui;
    void (MainWindow::*retFunction)(const QString);
};

#endif // DIALOGSTRING_H
