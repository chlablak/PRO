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
    const QString &getName() const;
    const int getId() const;
};

#endif // VISUALIZATION_IVERTEX_H
