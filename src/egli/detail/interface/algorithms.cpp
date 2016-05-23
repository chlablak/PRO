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
    std::vector<int> d;
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
    std::vector<int> d;
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
    egli::detail::algorithms::scc(RealType<Type::Graph>::cref g)
{
    return RealType<Type::Array>::type(
        GraphAlgorithm::stronglyConnectedComponent(g.graph()));
}

egli::detail::RealType<egli::Type::Graph>::type
    egli::detail::algorithms::kruskal(RealType<Type::Graph>::cref g)
{
    return RealType<egli::Type::Graph>::type(
        GraphAlgorithm::kruskal(g.graph()));
}
