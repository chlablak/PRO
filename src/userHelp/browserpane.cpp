/*! \brief main window for the user help interface
 *
 * \file browserpane.cpp
 * \author Christopher Browne
 * \date 22.04.2016
 */

#include "browserpane.h"

BrowserPane *BrowserPane::instance = nullptr;
QString *BrowserPane::_baseUrl = nullptr;

BrowserPane::BrowserPane(QWidget *parent) : parent(parent)
{
    searchBar = SearchBar::getInstance(parent);
    mainBrowser = MainBrowser::getInstance(parent, _baseUrl, searchBar);

    addWidget(searchBar);
    addWidget(mainBrowser);
}

BrowserPane *BrowserPane::getInstance(QWidget *parent, QString *baseUrl)
{
    if (instance == nullptr) {
        _baseUrl = baseUrl;
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
