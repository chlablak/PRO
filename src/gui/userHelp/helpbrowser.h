/*! \brief main help utility HTML browser
 *
 * \file helpbrowser.h
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

#ifndef HELPBROWSER_H
#define HELPBROWSER_H


class HelpBrowser : public QTextBrowser
{
    Q_OBJECT
private:
    QWidget *parent;
    QString baseUrl;
    static HelpBrowser *instance;

    HelpBrowser(QWidget *parent);

public:
	/*! \brief returns the instance of the HelpBrowser (singleton)
	 */
    static HelpBrowser* getInstance(QWidget *parent = 0);

public slots:
	/*! \brief displays the result HTML page
	 */
    void searchAsked(QString search);

};

#endif // HELPBROWSER_H
