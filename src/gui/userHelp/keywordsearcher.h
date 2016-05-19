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
private:
    QVector<HelpPage*> pages;
public:
	/*! \brief constructor
	 * \note must have the keyword index file, or throws an exception
	 */
    KeywordSearcher(QString indexFile);
	
	/*! \brief returns all the pages with a certain word
	 */
    QVector<HelpPage*> getPages(QString keyword);
};

#endif // KEYWORDSEARCHER_H
