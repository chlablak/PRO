/*! \brief simple object to encapsulate the info about a page
 *
 * \file helppage.cpp
 * \author Christopher Browne
 * \date 22.04.2016
 */


#include "helppage.h"

HelpPage::HelpPage(QString page, QString name, QStringList keywords) :
          page(page), name(name), keywords(keywords)
{

}

bool HelpPage::hasKeyword(QString word)
{
    for (QString k : keywords) {
        if (k.startsWith(word, Qt::CaseInsensitive)) {
            return true;
        }
    }

    return false;
}

QString HelpPage::getPage()
{
    return page;
}

QString HelpPage::getName()
{
    return name;
}
