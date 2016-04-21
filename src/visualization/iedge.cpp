#include "iedge.h"

IEdge::IEdge(IVertex *from, IVertex *to)
    : from(from), to(to)
{}

IEdge::~IEdge()
{}

IVertex *IEdge::getFrom()
{
    return from;
}

IVertex *IEdge::getTo()
{
    return to;
}

