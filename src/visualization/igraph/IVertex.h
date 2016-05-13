#ifndef VISUALIZATION_IGRAPH_IVERTEX_H
#define VISUALIZATION_IGRAPH_IVERTEX_H

#include <QString>

class IVertex
{
    static int count;

    QString name;
    int id;

public:
    IVertex(const QString &name);
    ~IVertex();
    const QString &getName() const;
    int getId() const;
};

#endif // VISUALIZATION_IGRAPH_IVERTEX_H
