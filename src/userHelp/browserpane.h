/*! \brief right pane of help window, contains main broswer and search bar
 *
 * \file browserpane.h
 * \author Christopher Browne
 * \date 22.04.2016
 */

#ifndef BROWSERPANE_H
#define BROWSERPANE_H

#include <QObject>
#include <QLayout>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <exception>

#include "mainbrowser.h"
#include "browserpane.h"
#include "keywordsearcher.h"

class BrowserPane : public QVBoxLayout
{
    Q_OBJECT

public:
    /*!
     * \brief returns an instance of the HelpWindow (singleton)
     * \param parent: parent widget
     * \param baseUrl: base url for html pages
     * \return BrowserPane*
     */
    static BrowserPane *getInstance(QWidget *parent, QString *baseUrl);

    /*!
     * \brief MainBrowser accessor
     * \return MainBrowser*
     */
    MainBrowser *getMainBrowser();
    SearchBar *getSearchBar();

private:
    BrowserPane(QWidget *parent);

    static BrowserPane *instance;
    static QString *_baseUrl;

    QWidget *parent;
    
    SearchBar *searchBar;
    MainBrowser *mainBrowser;
};

#endif // BROWSERPANE_H
