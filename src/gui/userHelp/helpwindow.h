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
    static HelpWindow* getInstance(QWidget *parent = 0);

signals:
    void searchResultsRequested(QString searchWord);

public slots:
    void searchAsked();
};

#endif // HELPWINDOW_H
