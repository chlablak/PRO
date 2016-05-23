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

public:
    /*!
     * \brief Returns the instance of the HelpBrowser (singleton)
     * \param parent: parent widget
     * \param baseUrl: base url for html files
     * \return MainBrowser*
     */
    static MainBrowser* getInstance(QWidget *parent, QString *baseUrl);

private:
    MainBrowser(QWidget *parent);

    static QString *_baseUrl;
    static MainBrowser *instance;
	
	QWidget *parent;

public slots:
    /*!
     * \brief Displays the result HTML page
     * \param search: search word
     */
    void searchAsked(QString search);

    /*!
     * \brief Loads specified html page
     * \param name: url of page
     */
    void setSource(const QUrl &name);
};

#endif // MAINBROWSER_H
