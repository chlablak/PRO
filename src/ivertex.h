#ifndef GRAPHY_IVERTEX_H
#define GRAPHY_IVERTEX_H

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

#endif // GRAPHY_IVERTEX_H
