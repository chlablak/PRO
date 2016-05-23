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
    searchBar = new SearchBar();
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
    QString resultPage = "<!DOCTYPE html><html><body><h1>Search results: \"";
    resultPage += searchWord + "\"</h1>";
    try {
        KeywordSearcher kws(keywordFile);
        resultPage += "<br/>";
        QVector<HelpPage*> fileList = kws.getPages(searchWord);
        int length = fileList.length();

        if (length == 0) {
            resultPage += "No results<hr/>";
        } else {
            if(length == 1) {
                resultPage += "1 result";
            } else {
                resultPage += QString::number(length) + " results";
            }
            resultPage += "<hr/><ul>";
            for (HelpPage *hp : fileList) {
                resultPage += "<li><a href=\"" + hp->getPage() + "\">" +
                              hp->getName() + "</a></li>";
            }
            resultPage += "</ul>";
        }

    } catch(QString e) {
        resultPage += "<hr/>Cannot find keyword file<hr/>";
    }

    resultPage += "</body></html>";

    emit searchResultsRequested(resultPage);
}
