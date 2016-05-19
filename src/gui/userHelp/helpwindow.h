/*! \brief main window for the user help interface
 *
 * \file helpwindow.h
 * \author Christopher Browne
 * \date 22.04.2016
 */

#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QObject>
#include <QLayout>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <exception>
#include "helpbrowser.h"
#include "searchbar.h"
#include "keywordsearcher.h"

class HelpWindow : public QVBoxLayout
{
    Q_OBJECT
private:
    static QString keywordFile;
    QWidget *parent;
    static HelpWindow *instance;
    SearchBar *searchBar;
    HelpBrowser *helpBrowser;

    HelpWindow(QWidget *parent);

public:
	/*! \brief returns and instance of the HelpWindow (singleton)
	 */
    static HelpWindow* getInstance(QWidget *parent = 0);

	/* \brief signal emitted to the HelpBrowser when a user enters a searchAsked
	 */
signals:
    void searchResultsRequested(QString searchWord);

	/* \brief slot called when user presses enter to start a searchAsked
	 */
public slots:
    void searchAsked();
};

#endif // HELPWINDOW_H
