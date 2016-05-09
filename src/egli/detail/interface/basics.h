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
//__graph_add
//__graph_sub
//__graph_create

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
