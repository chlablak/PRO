/*! \brief main window for the help GUI
 *
 * \file helpwindow.h
 * \author Christopher Browne
 * \date 22.04.2016
 */


#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QDialog>

#include "helpmainlayout.h"

class HelpWindow : public QDialog
{
public:
    /*!
     * \brief Returns an instance of HelpWindow (singleton)
     * \param parent: parent widget
     * \param baseUrl: base url for html files
     * \return HelpWindow*
     */
    static HelpWindow *getInstance(QWidget *parent, QString *baseUrl);

private:
    HelpWindow(QWidget *parent);

    static HelpWindow *instance;
    static QString *_baseUrl;

    QWidget *parent;
};

#endif // HELPWINDOW_H
