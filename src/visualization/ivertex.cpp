#include "ivertex.h"

IVertex::IVertex(const QString &name)
    : name(name)
{
    id = count++;
}

IVertex::~IVertex()
{}

QString &IVertex::getName()
{
    return name;
}

int IVertex::getId()
{
    return id;
}

int IVertex::count = 0;
