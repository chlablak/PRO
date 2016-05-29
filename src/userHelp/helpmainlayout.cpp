/*! \brief primary layout for the help GUI
 *
 * \file helpmainlayout.cpp
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
                     SIGNAL(mousePressed()),
                     rightPane->getMainBrowser(),
                     SLOT(backward()));

    QObject::connect(leftPane->getButtonPane()->getRight(),
                     SIGNAL(mousePressed()),
                     rightPane->getMainBrowser(),
                     SLOT(forward()));

    QObject::connect(rightPane->getSearchBar(),
                     SIGNAL(returnPressed()),
                     rightPane->getMainBrowser(),
                     SLOT(displaySearch()));

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
