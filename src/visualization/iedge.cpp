#include "iedge.h"

IEdge::IEdge(IVertex *from, IVertex *to)
    : from(from), to(to)
{}

IEdge::~IEdge()
{}

const IVertex *IEdge::getFrom() const
{
    return from;
}

const IVertex *IEdge::getTo() const
{
    return to;
}

