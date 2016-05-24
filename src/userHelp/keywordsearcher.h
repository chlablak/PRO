/*! \brief used to contains all the keyword searching logic
 *
 * \file keywordsearcher.h
 * \author Christopher Browne
 * \date 22.04.2016
 */

#ifndef KEYWORDSEARCHER_H
#define KEYWORDSEARCHER_H

#include <QVector>
#include <QString>
#include <QStringList>
#include <QFile>
#include <exception>

#include "helppage.h"
#include "filereader.h"

class KeywordSearcher
{
public:
    /*!
     * \brief constructor
     * \param indexFile
     * \note must have the keyword index file, or throws an exception
     */
    KeywordSearcher(QString indexFile);

    /*!
     * \brief Returns all the pages with a certain word
     * \param keyword: search word
     * \return
     */
    QVector<HelpPage*> getPages(QString keyword);

private:
    QVector<HelpPage*> pages;
};

#endif // KEYWORDSEARCHER_H
