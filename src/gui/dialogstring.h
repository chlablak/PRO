/*! \brief Window to get a string from the user
 *
 * \file dialogstring.h
 * \author Alain Hardy
 * \date 2.05.2016
 */

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
    /*!
     * \brief Constructor
     * \param parent: Widget designated as the parent of the window
     * \param title: Title of the window
     * \param buttonName: Label displayed on the button
     */
    explicit dialogString(QWidget *parent = 0, QString title = "New", QString buttonName = "Ok");
    ~dialogString();

signals:
    /*!
     * \brief Send the value typed into the text box the slot connected to this
     */
    void sendValue(const QString);

private slots:
    /*!
     * \brief Called when the user press on the button
     */
    void on_validateButton_clicked();

private:
    Ui::dialogString *ui;
    void (MainWindow::*retFunction)(const QString);
};

#endif // DIALOGSTRING_H
