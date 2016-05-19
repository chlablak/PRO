/*! \brief main window for the user help interface
 *
 * \file helpwindow.cpp
 * \author Christopher Browne
 * \date 22.04.2016
 */

#include "helpwindow.h"

HelpWindow* HelpWindow::instance = nullptr;
QString HelpWindow::keywordFile = "../UserHelp/pages/keywords.txt";

HelpWindow::HelpWindow(QWidget *parent) : parent(parent)
{
    searchBar = new SearchBar();
    helpBrowser = HelpBrowser::getInstance(parent);
    addWidget(searchBar);
    addWidget(helpBrowser);

    QObject::connect(searchBar, SIGNAL(returnPressed()),this,SLOT(searchAsked()));
    QObject::connect(this, SIGNAL(searchResultsRequested(QString)),helpBrowser, SLOT(searchAsked(QString)));
}

HelpWindow* HelpWindow::getInstance(QWidget *parent)
{
    if(instance == nullptr)
        instance = new HelpWindow(parent);
    return instance;
}

void HelpWindow::searchAsked(){
    QString searchWord = searchBar->text();
    QString resultPage = "<!DOCTYPE html><html><body><h1>Résultats pour la recherche: \"";
    resultPage += searchWord + "\"</h1>";
    try{
        KeywordSearcher kws(keywordFile);
        resultPage += "<br/>";
        QVector<HelpPage*> fileList = kws.getPages(searchWord);
        int length = fileList.length();
        if(length == 0){
            resultPage += "Aucun résultat<hr/>";
        }else{
            if(length == 1){
                resultPage += "1 résultat";
            }else{
                resultPage += QString::number(length) + " résultats";
            }
            resultPage += "<hr/><ul>";
            for(HelpPage *hp : fileList)
                resultPage += "<li><a href=\"" + hp->getPage() + "\">" + hp->getName() + "</a></li>";
            resultPage += "</ul>";
        }

    }catch(QString e){
        resultPage += "<hr/>Fichier des mots clés introuvable<hr/>";
    }

    resultPage += "</body></html>";
    emit searchResultsRequested(resultPage);
}
