/*! \brief used to contains all the keyword searching logic
 *
 * \file keywordsearcher.cpp
 * \author Christopher Browne
 * \date 22.04.2016
 */

#include "keywordsearcher.h"

KeywordSearcher::KeywordSearcher(QString indexFile)
{
    FileReader fr(indexFile);
    QString page;
    QString pageName;
    QStringList pageAndKeywords;
    QStringList keywords;

    for (QString str : fr.getStringList()) {
        pageAndKeywords = str.split(":", QString::SkipEmptyParts);
        page = pageAndKeywords[0];
        pageName = pageAndKeywords[1];
        keywords = pageAndKeywords[2].split("%", QString::SkipEmptyParts);
        pages.append(new HelpPage(page,pageName,keywords));
    }
}

QVector<HelpPage*> KeywordSearcher::getPages(QString keyword)
{
    QVector<HelpPage*> pagesWithKeyword;
    QStringList words = keyword.split(" ", QString::SkipEmptyParts);
    for (QString word : words) {
        for (HelpPage *hp : pages) {
            if (hp->hasKeyword(word) && !pagesWithKeyword.contains(hp)) {
                pagesWithKeyword.append(hp);
            }
        }
    }
    return pagesWithKeyword;
}

