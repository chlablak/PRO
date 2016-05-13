/*! \brief Basics functions to interface
 *
 * \file basics.h
 * \author Patrick Champion
 * \date 03.05.2016
 */

#ifndef EGLI_DETAIL_INTERFACE_BASICS_H_INCLUDED
#define EGLI_DETAIL_INTERFACE_BASICS_H_INCLUDED

#include "../../Type.h"
#include "../RealType.h"
#include "../../../utility/Optional.h"

namespace egli
{
namespace detail
{
namespace basics
{
/*! \brief Operator += for Graph
 *
 * \param graph - The Graph
 * \param infos - An array of Vertex and Edge
 * \return The new modified Graph
 *
 * \throw Exception (many reasons possible)
 */
RealType<Type::Graph>::type __graph_add_a(
    RealType<Type::Graph>::cref graph,
    RealType<Type::Array>::cref infos);

/*! \brief Operator += for Graph
 *
 * \param graph - The Graph
 * \param edge - An Edge
 * \return The new modified Graph
 *
 * \throw Exception (many reasons possible)
 */
RealType<Type::Graph>::type __graph_add_e(
    RealType<Type::Graph>::cref graph,
    RealType<Type::Edge>::cref edge);

/*! \brief Operator += for Graph
 *
 * \param graph - The Graph
 * \param vertex - A Vertex
 * \return The new modified Graph
 *
 * \throw Exception (many reasons possible)
 */
RealType<Type::Graph>::type __graph_add_v(
    RealType<Type::Graph>::cref graph,
    RealType<Type::Vertex>::cref vertex);

/*! \brief Operator -= for Graph
 *
 * \param graph - The Graph
 * \param infos - An array of Vertex and Edge
 * \return The new modified Graph
 *
 * \throw Exception (many reasons possible)
 */
RealType<Type::Graph>::type __graph_sub_a(
    RealType<Type::Graph>::cref graph,
    RealType<Type::Array>::cref infos);

/*! \brief Operator -= for Graph
 *
 * \param graph - The Graph
 * \param edge - An Edge
 * \return The new modified Graph
 *
 * \throw Exception (many reasons possible)
 */
RealType<Type::Graph>::type __graph_sub_e(
    RealType<Type::Graph>::cref graph,
    RealType<Type::Edge>::cref edge);

/*! \brief Operator -= for Graph
 *
 * \param graph - The Graph
 * \param vertex - A Vertex
 * \return The new modified Graph
 *
 * \throw Exception (many reasons possible)
 */
RealType<Type::Graph>::type __graph_sub_v(
    RealType<Type::Graph>::cref graph,
    RealType<Type::Vertex>::cref vertex);

/*! \brief Create a Graph
 *
 * \param infos - An array of Vertex and Edge
 * \return The created Graph
 *
 * \throw Exception if infos contains anything else than Vertex or Edge
 */
RealType<Type::Graph>::type __graph_create(RealType<Type::Array>::cref infos);

/*! \brief Create a Graph
 *
 * \param V - Shortcut for automatically add V vertrices
 * \param infos - An array of Vertex and Edge
 * \return The created Graph
 *
 * \throw Exception if infos contains anything else than Vertex or Edge
 */
RealType<Type::Graph>::type __graph_create_with_shortcut(
   RealType<Type::Integer>::cref V,
   RealType<Type::Array>::cref infos);

/*! \brief Create a Edge
 *
 * \param v - The vertex FROM
 * \param connection - The edge connection type
 * \param w - The vertex TO
 * \param id - The edge connection ID
 * \param weight - The edge optional weight
 * \param label - The edge optional label
 * \param maxCapacity - The edge optional max capacity
 * \param minCapacity - The edge optional min capacity
 * \return The created Edge
 */
RealType<Type::Edge>::type __edge_create(
    id_type v,
    RealType<Type::String>::cref connection,
    id_type w,
    const utility::Optional<id_type> &id,
    const utility::Optional<RealType<Type::Number>::type> &weight,
    const utility::Optional<RealType<Type::String>::type> &label,
    const utility::Optional<RealType<Type::Number>::type> &maxCapacity,
    const utility::Optional<RealType<Type::Number>::type> &minCapacity);

/*! \brief Create a Vertex
 *
 * \param id - The vertex ID
 * \param label - The vertex optional label
 * \param weight - The vertex optional weight
 * \param maxCapacity - The vertex optional max capacity
 * \param minCapacity - The vertex optional min capacity
 * \return The created Vertex
 */
RealType<Type::Vertex>::type __vertex_create(
    id_type id,
    const utility::Optional<RealType<Type::String>::type> &label,
    const utility::Optional<RealType<Type::Number>::type> &weight,
    const utility::Optional<RealType<Type::Number>::type> &maxCapacity,
    const utility::Optional<RealType<Type::Number>::type> &minCapacity);

/*! \brief Negate a number
 *
 * \param value - the value to negate
 * \return -value
 *
 * \note Declined in 3 versions, one for each Number-like type
 */
RealType<Type::Integer>::type __negate_i(RealType<Type::Integer>::cref value);
RealType<Type::Float>::type __negate_f(RealType<Type::Float>::cref value);
RealType<Type::Number>::type __negate_n(RealType<Type::Number>::cref value);
} // namespace basics
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_INTERFACE_BASICS_H_INCLUDED
