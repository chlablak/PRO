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
#include "keywordsearcher.h"

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
    static MainBrowser* getInstance(QWidget *parent,
                                    QString *baseUrl,
                                    SearchBar *searchBar);

private:
    MainBrowser(QWidget *parent, SearchBar *searchBar);

    static QString *_baseUrl;
    static MainBrowser *instance;
    static QString keywordFile;
	
	QWidget *parent;

    SearchBar *searchBar;

    QString getSearchHTML(const QString& searchWord);

public slots:
    /*!
     * \brief Displays the result HTML page
     * \param search: search word
     */
    void displaySearch();

    /*!
     * \brief Loads specified html page
     * \param name: url of page
     */
    void setSource(const QUrl &name) Q_DECL_OVERRIDE;

    /*!
     * \brief Loads next page if there is one. Overridden to enable
     *  use of search queries
     */
    void forward() Q_DECL_OVERRIDE;

    /*!
     * \brief Loads previous page if there is one. Overridden to enable
     *  use of search queries
     */
    void backward() Q_DECL_OVERRIDE;
};

#endif // MAINBROWSER_H
