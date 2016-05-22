/*! \brief main help window, acts as controller for all signals/slots
 *
 * \file helpwindow.cpp
 * \author Christopher Browne
 * \date 14.05.2016
 */

#include "helpmainlayout.h"

HelpMainLayout *HelpMainLayout::instance = nullptr;
QString *HelpMainLayout::_baseUrl = nullptr;

HelpMainLayout::HelpMainLayout(QWidget *parent) : parent(parent)
{
    leftPane = NavigationPane::getInstance(parent, _baseUrl);
    rightPane = BrowserPane::getInstance(parent, _baseUrl);

    addLayout(leftPane);
    addLayout(rightPane);

    QObject::connect(leftPane->getButtonPane()->getLeft(),
                     SIGNAL(clicked(bool)),
                     rightPane->getMainBrowser(),
                     SLOT(backward()));

    QObject::connect(leftPane->getButtonPane()->getRight(),
                     SIGNAL(clicked(bool)),
                     rightPane->getMainBrowser(),
                     SLOT(forward()));

    QObject::connect(rightPane->getSearchBar(),
                     SIGNAL(returnPressed()),
                     rightPane,
                     SLOT(searchAsked()));

    QObject::connect(rightPane,
                     SIGNAL(searchResultsRequested(QString)),
                     rightPane->getMainBrowser(),
                     SLOT(searchAsked(QString)));

    QObject::connect(leftPane->getNavMenu(),
                     SIGNAL(anchorClicked(QUrl)),
                     rightPane->getMainBrowser(),
                     SLOT(setSource(QUrl)));

}

HelpMainLayout *HelpMainLayout::getInstance(QWidget *parent, QString *baseUrl)
{
    if (instance == nullptr) {
        _baseUrl = baseUrl;
        instance = new HelpMainLayout(parent);
    }
    return instance;
}
