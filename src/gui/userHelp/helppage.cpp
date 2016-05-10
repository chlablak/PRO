#include "helppage.h"

HelpPage::HelpPage(QString page, QString name, QStringList keywords) : page(page), name(name), keywords(keywords)
{

}

bool HelpPage::hasKeyword(QString word)
{
    return keywords.contains(word);
}

QString HelpPage::getPage()
{
    return page;
}

QString HelpPage::getName()
{
    return name;
}
