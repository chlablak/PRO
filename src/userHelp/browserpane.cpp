/*! \brief main window for the user help interface
 *
 * \file browserpane.cpp
 * \author Christopher Browne
 * \date 22.04.2016
 */

#include "browserpane.h"

BrowserPane *BrowserPane::instance = nullptr;
QString *BrowserPane::_baseUrl = nullptr;
QString BrowserPane::keywordFile = nullptr;

BrowserPane::BrowserPane(QWidget *parent) : parent(parent)
{
    searchBar = SearchBar::getInstance(parent);
    mainBrowser = MainBrowser::getInstance(parent, _baseUrl);

    addWidget(searchBar);
    addWidget(mainBrowser);
}

BrowserPane *BrowserPane::getInstance(QWidget *parent, QString *baseUrl)
{
    if (instance == nullptr) {
        _baseUrl = baseUrl;
        keywordFile = *baseUrl + "keywords.txt";
        instance = new BrowserPane(parent);
    }
    return instance;
}

MainBrowser *BrowserPane::getMainBrowser()
{
    return mainBrowser;
}

SearchBar *BrowserPane::getSearchBar()
{
    return searchBar;
}

void BrowserPane::searchAsked(){
    QString searchWord = searchBar->text();
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

    emit searchResultsRequested(searchHtml);
}
