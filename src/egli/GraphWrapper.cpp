/*! \brief Wrap the IGraph class
 *
 * \file GraphWrapper.cpp
 * \author Patrick Champion
 * \date 12.05.2016
 */

#include "GraphWrapper.h"

egli::GraphWrapper::GraphWrapper(igraph_ptr_t g) :
    m_graph(g)
{}

egli::GraphWrapper::GraphWrapper(const GraphWrapper &o) :
    m_graph(nullptr)//o.graph() ? o.graph()->clone() : nullptr)
{
    #warning GraphWrapper copy ctor TODO
}

egli::GraphWrapper::~GraphWrapper()
{
    delete m_graph;
}

egli::GraphWrapper &egli::GraphWrapper::operator=(igraph_ptr_t g)
{
    GraphWrapper tmp(g);
    std::swap(m_graph, tmp.m_graph);
    return *this;
}

egli::GraphWrapper &egli::GraphWrapper::operator=(const GraphWrapper &o)
{
    GraphWrapper tmp(o);
    std::swap(m_graph, tmp.m_graph);
    return *this;
}

egli::GraphWrapper::igraph_ptr_t egli::GraphWrapper::graph()
{
    return m_graph;
}

const egli::GraphWrapper::igraph_ptr_t egli::GraphWrapper::graph() const
{
    return m_graph;
}
