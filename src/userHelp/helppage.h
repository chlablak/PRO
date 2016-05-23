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
public:
    HelpPage(QString page, QString name, QStringList keywords);

    /*!
     * \brief checks for a keyword or part of keyword (case insensitive)
     * \param word
     * \return bool: if keyword is present for this page
     */
    bool hasKeyword(QString word);

    /*!
     * \brief Page accessor
     * \return
     */
    QString getPage();

    /*!
     * \brief page name accessor
     * \return
     */
    QString getName();

private:
    QString page;
    QString name;
    QStringList keywords;
};

#endif // HELPPAGE_H
