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
private:
    BrowserPane(QWidget *parent);

    static BrowserPane *instance;
    static QString *_baseUrl;
    static QString keywordFile;
	
    QWidget *parent;
    
    SearchBar *searchBar;
    MainBrowser *mainBrowser;

public:
	/*! \brief returns an instance of the HelpWindow (singleton)
	 */
    static BrowserPane *getInstance(QWidget *parent, QString *baseUrl);

    MainBrowser *getMainBrowser();
    SearchBar *getSearchBar();

signals:
    /* \brief signal emitted to the HelpBrowser when a user enters a search
     */
    void searchResultsRequested(QString searchWord);

public slots:
    /* \brief slot called when user presses enter to start a searchAsked
     */
    void searchAsked();
};

#endif // BROWSERPANE_H
