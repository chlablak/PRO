#include "keywordsearcher.h"

KeywordSearcher::KeywordSearcher(QString indexFile)
{
    FileReader fr(indexFile);
    QString page;
    QString pageName;
    QStringList pageAndKeywords;
    QStringList keywords;
    for(QString str : fr.getStringList()){
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
    for(HelpPage *hp : pages)
        if(hp->hasKeyword(keyword))
            pagesWithKeyword.append(hp);

    return pagesWithKeyword;
}

