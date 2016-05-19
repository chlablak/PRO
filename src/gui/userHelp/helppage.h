/*! \brief simple object to encapsulate the info about a page
 *
 * \file helppage.h
 * \author Christopher Browne
 * \date 22.04.2016
 */

#ifndef HELPPAGE_H
#define HELPPAGE_H

#include <QString>
#include <QStringList>

class HelpPage
{
private:
    QString page;
    QString name;
    QStringList keywords;

public:
    HelpPage(QString page, QString name, QStringList keywords);
    bool hasKeyword(QString word);
    QString getPage();
    QString getName();
};

#endif // HELPPAGE_H
