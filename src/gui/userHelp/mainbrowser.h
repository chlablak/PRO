/*! \brief main help utility HTML browser
 *
 * \file mainbrowser.h
 * \author Christopher Browne
 * \date 22.04.2016
 */

#include <QMouseEvent>
#include <QLabel>
#include <QTextEdit>
#include <QTextBrowser>
#include <QUrl>
#include <QStringList>
#include <QVector>
#include <QDir>
#include <QTextStream>
#include <exception>

#include "filereader.h"
#include "searchBar.h"

#ifndef MAINBROWSER_H
#define MAINBROWSER_H


class MainBrowser : public QTextBrowser
{
    Q_OBJECT
private:
    MainBrowser(QWidget *parent);

    static QString *_baseUrl;
    static MainBrowser *instance;
	
	QWidget *parent;

public:
	/*! \brief returns the instance of the HelpBrowser (singleton)
	 */
    static MainBrowser* getInstance(QWidget *parent, QString *baseUrl);

public slots:
	/*! \brief displays the result HTML page
	 */
    void searchAsked(QString search);
    void setSource(const QUrl &name);

};

#endif // MAINBROWSER_H
