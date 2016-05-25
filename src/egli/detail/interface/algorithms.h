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

/*! \brief Apply the SCC Tarjan (strongly connected component) visitor
 *
 * \param g - The Graph
 * \return An Array that associate the Vertex ID with its SCC
 *
 * \throw Exception if an error occurs
 */
RealType<Type::Array>::type tarjan(RealType<Type::Graph>::cref g);

/*! \brief Apply the Kruskal visitor
 *
 * \param g - The Graph
 * \return The resulting Graph
 *
 * \throw Exception if an error occurs
 */
RealType<Type::Graph>::type kruskal(RealType<Type::Graph>::cref g);

/*! \brief Apply the Prim visitor
 *
 * \param g - The Graph
 * \param from - The origin vertex ID (optional)
 * \return The resulting Graph
 *
 * \throw Exception if an error occurs
 */
RealType<Type::Graph>::type prim_1(RealType<Type::Graph>::cref g);
RealType<Type::Graph>::type prim_2(RealType<Type::Graph>::cref g,
                                   RealType<Type::Integer>::cref from);

/*! \brief Check if a Graph is ...
 *
 * \param g - The Graph
 * \return true if g matches the criteria
 *
 * \throw Exception if an error occurs
 */
RealType<Type::Boolean>::type isConnected(RealType<Type::Graph>::cref g);
RealType<Type::Boolean>::type isDirected(RealType<Type::Graph>::cref g);
RealType<Type::Boolean>::type isEmpty(RealType<Type::Graph>::cref g);
RealType<Type::Boolean>::type isNegativeWeighted(RealType<Type::Graph>::cref g);
RealType<Type::Boolean>::type isNull(RealType<Type::Graph>::cref g);
RealType<Type::Boolean>::type isPlanar(RealType<Type::Graph>::cref g);
RealType<Type::Boolean>::type isSimple(RealType<Type::Graph>::cref g);
RealType<Type::Boolean>::type isStronglyConnected(RealType<Type::Graph>::cref g);
RealType<Type::Boolean>::type isWeighted(RealType<Type::Graph>::cref g);
} // namespace algorithms
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_INTERFACE_ALGORITHMS_H_INCLUDED
