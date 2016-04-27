/*! \brief Edge structure
 *
 * \file Edge.h
 * \author Patrick Champion
 * \date 26.04.2016
 */

#ifndef EGLI_EDGE_H_INCLUDED
#define EGLI_EDGE_H_INCLUDED

#include "Type.h"
#include "detail/RealType.h"
#include "../utility/Optional.h"

namespace egli
{
struct Edge
{
    // Useful typedefs
    using string_t = detail::RealType<Type::String>::type;
    using number_t = detail::RealType<Type::Number>::type;

    // Attributes
    id_type id;
    utility::Optional<number_t> weight;
    utility::Optional<string_t> label;
    utility::Optional<number_t> maxCapacity;
    utility::Optional<number_t> minCapacity;

    /*! \brief Constructor
     *
     * \param id - The vertex ID
     * \param weight - The vertex optional weight
     * \param label - The vertex optional label
     * \param maxCapacity - The vertex optional max capacity
     * \param minCapacity - The vertex optional min capacity
     */
    Edge(id_type id,
        const utility::Optional<number_t> &weight = {},
        const utility::Optional<string_t> &label = {},
        const utility::Optional<number_t> &maxCapacity = {},
        const utility::Optional<number_t> &minCapacity = {});
};
}

#endif // EGLI_EDGE_H_INCLUDED
