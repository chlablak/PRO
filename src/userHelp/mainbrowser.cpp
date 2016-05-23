/*! \brief main help utility HTML browser
 *
 * \file mainbrowser.cpp
 * \author Christopher Browne
 * \date 22.04.2016
 */

#include "mainbrowser.h"

MainBrowser* MainBrowser::instance = nullptr;
QString *MainBrowser::_baseUrl = nullptr;

MainBrowser::MainBrowser(QWidget *parent) : parent(parent)
{
    setSearchPaths(QStringList(*_baseUrl));
    setSource(QUrl(*_baseUrl + "home.html"));
    setOpenExternalLinks(true);
    show();
}

MainBrowser* MainBrowser::getInstance(QWidget *parent, QString *baseUrl)
{
    if (instance == nullptr) {
        _baseUrl = baseUrl;
        instance = new MainBrowser(parent);
    }
    return instance;
}

void MainBrowser::searchAsked(QString resultPage)
{
    setHtml(resultPage);
}

void MainBrowser::setSource(const QUrl &name)
{
    QTextBrowser::setSource(name);
    if(document()->isEmpty())
        setHtml("<!DOCTYPE html><html><body><h1>Oops! 404!</h1><hr/>"
                "<h2>It looks like this page doesn't exist...</h2>"
                "<h3>Go <a href= " + *_baseUrl + "home.html>Home</a>?</h3>"
                "</body></html>");
}
