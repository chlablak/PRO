/*! \brief Vertex structure
 *
 * \file Vertex.h
 * \author Patrick Champion
 * \date 26.04.2016
 */

#ifndef EGLI_VERTEX_H_INCLUDED
#define EGLI_VERTEX_H_INCLUDED

#include "detail/Types.h"
#include "../utility/Optional.h"

namespace egli
{
struct Vertex
{
    // Attributes
    detail::id_type id;
    utility::Optional<detail::RealType<detail::Type::String>::type> label;
    utility::Optional<detail::RealType<detail::Type::Number>::type> weight;
    utility::Optional<detail::RealType<detail::Type::Number>::type> maxCapacity;
    utility::Optional<detail::RealType<detail::Type::Number>::type> minCapacity;

    /*! \brief Constructor
     *
     * \param id - The vertex ID
     * \param label - The vertex optional label
     * \param weight - The vertex optional weight
     * \param maxCapacity - The vertex optional max capacity
     * \param minCapacity - The vertex optional min capacity
     */
    Vertex(detail::id_type id,
        const utility::Optional<detail::RealType<detail::Type::String>::type> &label = {},
        const utility::Optional<detail::RealType<detail::Type::Number>::type> &weight = {},
        const utility::Optional<detail::RealType<detail::Type::Number>::type> &maxCapacity = {},
        const utility::Optional<detail::RealType<detail::Type::Number>::type> &minCapacity = {});
};
}

#endif // EGLI_VERTEX_H_INCLUDED
