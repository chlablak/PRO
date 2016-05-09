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
    KeywordSearcher(QString indexFile);
    QVector<HelpPage*> getPages(QString keyword);
};

#endif // KEYWORDSEARCHER_H
