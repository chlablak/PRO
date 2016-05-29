/*! \brief Vertex structure
 *
 * \file TVertex.h (T for Type)
 * \author Patrick Champion
 * \date 26.04.2016
 */

#ifndef EGLI_VERTEX_H_INCLUDED
#define EGLI_VERTEX_H_INCLUDED

#include "Type.h"
#include "detail/RealType.h"
#include "../utility/Optional.h"

namespace egli
{
/*! \brief Vertex type
 */
struct Vertex
{
    // Useful typedefs
    using string_t = detail::RealType<Type::String>::type;
    using number_t = detail::RealType<Type::Number>::type;

    // Attributes
    id_type id;
    utility::Optional<string_t> label;
    utility::Optional<number_t> weight;
    utility::Optional<number_t> maxCapacity;
    utility::Optional<number_t> minCapacity;

    /*! \brief Constructor
     *
     * \param id - The vertex ID
     * \param label - The vertex optional label
     * \param weight - The vertex optional weight
     * \param maxCapacity - The vertex optional max capacity
     * \param minCapacity - The vertex optional min capacity
     */
    Vertex(id_type id = 0,
        const utility::Optional<string_t> &label = {},
        const utility::Optional<number_t> &weight = {},
        const utility::Optional<number_t> &maxCapacity = {},
        const utility::Optional<number_t> &minCapacity = {});

    // Move is dangerous for this type
    Vertex(const Vertex&) = default;
    Vertex &operator=(const Vertex&) = default;
};
}

#endif // EGLI_VERTEX_H_INCLUDED
