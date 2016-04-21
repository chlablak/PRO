#ifndef VISUALIZATION_IEDGE_H
#define VISUALIZATION_IEDGE_H

#include "ivertex.h"

class IEdge
{
    IVertex *from;
    IVertex *to;

public:
    IEdge(IVertex *from, IVertex *to);
    ~IEdge();
    IVertex *getFrom();
    IVertex *getTo();
};

#endif // VISUALIZATION_IEDGE_H
