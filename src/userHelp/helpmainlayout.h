/*! \brief main help window, acts as controller for all signals/slots
 *
 * \file helpwindow.h
 * \author Christopher Browne
 * \date 14.05.2016
 */

#ifndef HELPMAINLAYOUT_H
#define HELPMAINLAYOUT_H

#include <QHBoxLayout>
#include <QString>
#include <iostream>

#include "navigationpane.h"
#include "browserpane.h"

class HelpMainLayout : public QHBoxLayout
{
public:
    /*!
     * \brief Returns an instance of HelpWindow (singleton)
     * \param parent: parent widget
     * \param baseUrl: base url for html files
     * \return
     */
    static HelpMainLayout *getInstance(QWidget *parent, QString *baseUrl);

private:
    HelpMainLayout(QWidget *parent);
	
    static HelpMainLayout *instance;
    static QString *_baseUrl;

    QWidget *parent;
	
    NavigationPane *leftPane;
    BrowserPane *rightPane;
};

#endif // HELPMAINLAYOUT_H
