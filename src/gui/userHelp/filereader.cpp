#include "filereader.h"

FileReader::FileReader(QString fileName) : fileName(fileName)
{
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly))
       throw QString("Fichier introuvable");

    QTextStream in(&file);
    while(!in.atEnd())
        lines.append(in.readLine());

    file.close();
}

QStringList FileReader::getStringList(){
    return lines;
}

QString FileReader::getString(){
    QString str = "";
    for(QString s : lines)
        str += s;
    return str;
}

