#include "helpbrowser.h"

HelpBrowser* HelpBrowser::instance = nullptr;

HelpBrowser::HelpBrowser(QWidget * parent) : parent(parent)
{
    baseUrl = QString("../userHelp/pages/");
    setSearchPaths(QStringList(baseUrl));

    QString content = "";

    try{
       FileReader fr(baseUrl + "home.html");
       setHtml(fr.getString());
    }
    catch(QString e){
        setHtml("Fichiers d'aide introuvables");
    }

    show();
}

HelpBrowser* HelpBrowser::getInstance(QWidget *parent)
{
    if(instance == nullptr)
        instance = new HelpBrowser(parent);
    return instance;
}

void HelpBrowser::searchAsked(QString resultPage){
    setHtml(resultPage);
}
