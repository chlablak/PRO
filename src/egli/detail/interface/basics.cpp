/*! \brief Basics functions to interface
 *
 * \file basics.cpp
 * \author Patrick Champion
 * \date 03.05.2016
 */

#include "basics.h"
#include "../../Number.h"
#include "../../Vertex.h"
#include "../../Edge.h"

egli::detail::RealType<egli::Type::Edge>::type
    egli::detail::basics::__edge_create(
        id_type v,
        RealType<Type::String>::cref connection,
        id_type w,
        const utility::Optional<id_type> &id,
        const utility::Optional<RealType<Type::Number>::type> &weight,
        const utility::Optional<RealType<Type::String>::type> &label,
        const utility::Optional<RealType<Type::Number>::type> &maxCapacity,
        const utility::Optional<RealType<Type::Number>::type> &minCapacity)
{
    Edge::Connection conn =
        connection == "--" ?
            Edge::Connection::Bidirectional :
            Edge::Connection::Unidirectional;
    if (conn == Edge::Connection::Unidirectional && connection == "<-")
        std::swap(v, w);
    return Edge(v, w, conn, id, weight, label, maxCapacity, minCapacity);
}

egli::detail::RealType<egli::Type::Vertex>::type
    egli::detail::basics::__vertex_create(
        id_type id,
        const utility::Optional<RealType<Type::String>::type> &label,
        const utility::Optional<RealType<Type::Number>::type> &weight,
        const utility::Optional<RealType<Type::Number>::type> &maxCapacity,
        const utility::Optional<RealType<Type::Number>::type> &minCapacity)
{
    return Vertex(id, label, weight, maxCapacity, minCapacity);
}

egli::detail::RealType<egli::Type::Integer>::type
    egli::detail::basics::__negate_i(RealType<Type::Integer>::cref value)
{
    return -value;
}

egli::detail::RealType<egli::Type::Float>::type
    egli::detail::basics::__negate_f(RealType<Type::Float>::cref value)
{
    return -value;
}

egli::detail::RealType<egli::Type::Number>::type
    egli::detail::basics::__negate_n(RealType<Type::Number>::cref value)
{
    return -value;
}
