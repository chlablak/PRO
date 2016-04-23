#ifndef FILEREADER_H
#define FILEREADER_H

#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>

class FileReader
{
private:
    QString fileName;
    QStringList lines;

public:
    FileReader(QString fileName);
    QStringList getStringList();
    QString getString();
};

#endif // FILEREADER_H
