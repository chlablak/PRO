#ifndef VISUALIZATION_IVERTEX_H
#define VISUALIZATION_IVERTEX_H

#include <QString>

class IVertex
{
    static int count;

    QString name;
    int id;

public:
    IVertex(const QString &name);
    ~IVertex();
    QString &getName();
    int getId();
};

#endif // VISUALIZATION_IVERTEX_H
