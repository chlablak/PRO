#include "ivertex.h"

IVertex::IVertex(const QString &name)
    : name(name)
{
    id = count++;
}

IVertex::~IVertex()
{}

const QString &IVertex::getName() const
{
    return name;
}

const int IVertex::getId() const
{
    return id;
}

int IVertex::count = 0;
