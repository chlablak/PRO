#ifndef VISUALIZATION_IVERTEX_H
#define VISUALIZATION_IVERTEX_H

#include <QString>

class IVertex
{
    QString name;

public:
    IVertex(const QString &name)
        : name(name)
    {}

    QString &getName()
    {
        return name;
    }

    ~IVertex()
    {}
};

#endif // VISUALIZATION_IVERTEX_H
