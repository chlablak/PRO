/*! \brief Window to get a string from the user
 *
 * \file dialogstring.cpp
 * \author Alain Hardy
 * \date 2.05.2016
 */

#include "dialogstring.h"
#include "ui_dialogstring.h"

dialogString::dialogString(QWidget *parent, QString title, QString buttonName) :
    QDialog(parent),
    ui(new Ui::dialogString)
{
    ui->setupUi(this);
    setWindowTitle(title);
    ui->validateButton->setText(buttonName);

    ui->stringEdit->setFocus();
}

dialogString::~dialogString()
{
    delete ui;
}

void dialogString::on_validateButton_clicked()
{
    emit sendValue(ui->stringEdit->text());
    this->close();
}
