/*! \brief Algorithms functions to interface
 *
 * \file algorithms.cpp
 * \author Patrick Champion
 * \date 03.05.2016
 */

#include "algorithms.h"
#include "../../Array.h"
#include "../../GraphWrapper.h"
#include "../../TVertex.h"

egli::detail::RealType<egli::Type::Array>::type
    egli::detail::algorithms::bfs(RealType<Type::Graph>::cref g,
                                  RealType<Type::Integer>::cref from)
{
    std::vector<double> d;
    ::Vertex *f = g.getVertexById(from);
    RealType<Type::Array>::type result;
    result.add(GraphAlgorithm::bfs(g.graph(), f, d));
    result.add(RealType<Type::Array>::type(d));
    return result;
}

egli::detail::RealType<egli::Type::Array>::type
    egli::detail::algorithms::dfs(RealType<Type::Graph>::cref g,
                                  RealType<Type::Integer>::cref from)
{
    std::vector<double> d;
    ::Vertex *f = g.getVertexById(from);
    RealType<Type::Array>::type result;
    result.add(GraphAlgorithm::dfs(g.graph(), f, d));
    result.add(RealType<Type::Array>::type(d));
    return result;
}

egli::detail::RealType<egli::Type::Array>::type
    egli::detail::algorithms::cc(RealType<Type::Graph>::cref g)
{
    return RealType<Type::Array>::type(
        GraphAlgorithm::connectedComponent(g.graph()));
}

egli::detail::RealType<egli::Type::Array>::type
    egli::detail::algorithms::tarjan(RealType<Type::Graph>::cref g)
{
    return RealType<Type::Array>::type(
        GraphAlgorithm::stronglyConnectedComponent(g.graph()));
}

egli::detail::RealType<egli::Type::Graph>::type
    egli::detail::algorithms::kruskal(RealType<Type::Graph>::cref g)
{
    return RealType<Type::Graph>::type(GraphAlgorithm::kruskal(g.graph()));
}

egli::detail::RealType<egli::Type::Graph>::type
    egli::detail::algorithms::prim_1(RealType<Type::Graph>::cref g)
{
    return RealType<Type::Graph>::type(GraphAlgorithm::prim(g.graph()));
}

egli::detail::RealType<egli::Type::Graph>::type
    egli::detail::algorithms::prim_2(RealType<Type::Graph>::cref g,
                                     RealType<Type::Integer>::cref from)
{
    ::Vertex *f = g.getVertexById(from);
    return RealType<Type::Graph>::type(GraphAlgorithm::prim(g.graph(), f));
}

egli::detail::RealType<egli::Type::Boolean>::type
    egli::detail::algorithms::isConnected(RealType<Type::Graph>::cref g)
{
    return g.graph()->isConnected();
}

egli::detail::RealType<egli::Type::Boolean>::type
    egli::detail::algorithms::isDirected(RealType<Type::Graph>::cref g)
{
    return g.graph()->isDirected();
}

egli::detail::RealType<egli::Type::Boolean>::type
    egli::detail::algorithms::isEmpty(RealType<Type::Graph>::cref g)
{
    return g.graph()->isEmpty();
}

egli::detail::RealType<egli::Type::Boolean>::type
    egli::detail::algorithms::isNegativeWeighted(RealType<Type::Graph>::cref g)
{
    return g.graph()->isNegativeWeighted();
}

egli::detail::RealType<egli::Type::Boolean>::type
    egli::detail::algorithms::isNull(RealType<Type::Graph>::cref g)
{
    return g.graph()->isNull();
}

egli::detail::RealType<egli::Type::Boolean>::type
    egli::detail::algorithms::isPlanar(RealType<Type::Graph>::cref g)
{
    return g.graph()->isPlanar();
}

egli::detail::RealType<egli::Type::Boolean>::type
    egli::detail::algorithms::isSimple(RealType<Type::Graph>::cref g)
{
    return g.graph()->isSimple();
}

egli::detail::RealType<egli::Type::Boolean>::type
    egli::detail::algorithms::isStronglyConnected(RealType<Type::Graph>::cref g)
{
    return g.graph()->isStronglyConnected();
}

egli::detail::RealType<egli::Type::Boolean>::type
    egli::detail::algorithms::isWeighted(RealType<Type::Graph>::cref g)
{
    return g.graph()->isWeighted();
}

egli::detail::RealType<egli::Type::Array>::type
    egli::detail::algorithms::bellmanFord(RealType<Type::Graph>::cref g,
                                          RealType<Type::Integer>::cref from)
{
    std::vector<double> d;
    ::Vertex *f = g.getVertexById(from);
    RealType<Type::Array>::type result;
    result.add(GraphAlgorithm::bellmanFord(g.graph(), f, d));
    result.add(RealType<Type::Array>::type(d));
    return result;
}

egli::detail::RealType<egli::Type::Graph>::type
    egli::detail::algorithms::detectCycle(RealType<Type::Graph>::cref g)
{
    return RealType<Type::Graph>::type(GraphAlgorithm::detectCycle(g.graph()));
}
