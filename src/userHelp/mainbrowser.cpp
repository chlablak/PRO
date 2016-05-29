/*! \brief main help utility HTML browser
 *
 * \file mainbrowser.cpp
 * \author Christopher Browne
 * \date 22.04.2016
 */

#include "mainbrowser.h"
#include <iostream>

MainBrowser* MainBrowser::instance = nullptr;
QString *MainBrowser::_baseUrl = nullptr;
QString MainBrowser::keywordFile = nullptr;

MainBrowser::MainBrowser(QWidget *parent, SearchBar *searchBar) :
    parent(parent),
    searchBar(searchBar)
{
    setSearchPaths(QStringList(*_baseUrl));
    setSource(QUrl("home.html"));
    setOpenExternalLinks(true);
    show();
}

MainBrowser* MainBrowser::getInstance(QWidget *parent,
                                      QString *baseUrl,
                                      SearchBar *searchBar)
{
    if (instance == nullptr) {
        _baseUrl = baseUrl;
        keywordFile = *baseUrl + "keywords.txt";
        instance = new MainBrowser(parent, searchBar);
    }
    return instance;
}

void MainBrowser::displaySearch()
{
    QString searchWord = searchBar->text();
    setSource(QUrl("search.html?" + searchWord));

}

void MainBrowser::setSource(const QUrl &link)
{
    QTextBrowser::setSource(link);
    if (link.hasQuery()) {
        setHtml(toHtml() + getSearchHTML(link.query()));
    }
    if (document()->isEmpty()) {
        setHtml("<!DOCTYPE html><html><body><h1>Oops! 404!</h1><hr/>"
                "<h2>It looks like this page doesn't exist...</h2>"
                "<h3>Go <a href= " + *_baseUrl + "home.html>Home</a>?</h3>"
                "</body></html>");
    }
}

QString MainBrowser::getSearchHTML(const QString& searchWord)
{
    QString searchHtml = "<h2>Search term: " + searchWord + "</h2>";
    try {
        KeywordSearcher kws(keywordFile);
        QVector<HelpPage*> fileList = kws.getPages(searchWord);
        int length = fileList.length();

        if (length == 0) {
            searchHtml += "No results";
        } else {
            if(length == 1) {
                searchHtml += "1 result";
            } else {
                searchHtml += QString::number(length) + " results";
            }
            searchHtml += "<ul>";
            for (HelpPage *hp : fileList) {
                searchHtml += "<li><a href=\"" + hp->getPage() + "\">" +
                              hp->getName() + "</a></li>";
            }
            searchHtml += "</ul>";
        }

    } catch(QString e) {
        searchHtml += "Cannot find keyword file";
    }

    searchHtml += "</body></html>";
    return searchHtml;
}

void MainBrowser::forward()
{
    QUrl next = historyUrl(1);
    if (!next.isEmpty()) {
        QTextBrowser::forward();
        if (source().hasQuery()) {
            setSource(source());
        }
    }
}

void MainBrowser::backward()
{
    QUrl prev = historyUrl(-1);
    if (!prev.isEmpty()) {
        QTextBrowser::backward();
        if (source().hasQuery()) {
            setSource(source());
        }
    }
}
