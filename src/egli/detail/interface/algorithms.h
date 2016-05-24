/*! \brief Algorithms functions to interface
 *
 * \file algorithms.h
 * \author Patrick Champion
 * \date 03.05.2016
 */

#ifndef EGLI_DETAIL_INTERFACE_ALGORITHMS_H_INCLUDED
#define EGLI_DETAIL_INTERFACE_ALGORITHMS_H_INCLUDED

#include "../RealType.h"
#include "../../Type.h"

namespace egli
{
namespace detail
{
namespace algorithms
{
/*! \brief Apply the BFS visitor
 *
 * \param g - The Graph
 * \param from - The origin Vertex ID
 * \return [0] => The resulting Graph
 *         [1] => Distances Array
 *
 * \throw Exception if an error occurs
 */
RealType<Type::Array>::type
    bfs(RealType<Type::Graph>::cref g, RealType<Type::Integer>::cref from);

/*! \brief Apply the DFS visitor
 *
 * \param g - The Graph
 * \param from - The origin Vertex ID
 * \return [0] => The resulting Graph
 *         [1] => Input dates Array
 *
 * \throw Exception if an error occurs
 */
RealType<Type::Array>::type
    dfs(RealType<Type::Graph>::cref g, RealType<Type::Integer>::cref from);

/*! \brief Apply the CC (connected component) visitor
 *
 * \param g - The Graph
 * \return An Array that associate the Vertex ID with its CC
 *
 * \throw Exception if an error occurs
 */
RealType<Type::Array>::type cc(RealType<Type::Graph>::cref g);

/*! \brief Apply the SCC (strongly connected component) visitor
 *
 * \param g - The Graph
 * \return An Array that associate the Vertex ID with its SCC
 *
 * \throw Exception if an error occurs
 */
RealType<Type::Array>::type scc(RealType<Type::Graph>::cref g);

/*! \brief Apply the Kruskal visitor
 *
 * \param g - The Graph
 * \return The resulting Graph
 *
 * \throw Exception if an error occurs
 */
RealType<Type::Graph>::type kruskal(RealType<Type::Graph>::cref g);
} // namespace algorithms
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_INTERFACE_ALGORITHMS_H_INCLUDED
