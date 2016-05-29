/*! \brief Edge structure
 *
 * \file TEdge.h (T for Type)
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
/*! \brief Edge type
 */
struct Edge
{
    // Useful typedefs
    using string_t = detail::RealType<Type::String>::type;
    using number_t = detail::RealType<Type::Number>::type;

    // Edge connection type
    enum class Connection
    {
        Unidirectional,
        Bidirectional
    };

    // Attributes
    id_type v;
    id_type w;
    Connection connection;
    utility::Optional<id_type> id;
    utility::Optional<number_t> weight;
    utility::Optional<string_t> label;
    utility::Optional<number_t> maxCapacity;
    utility::Optional<number_t> minCapacity;

    /*! \brief Constructor
     *
     * \param v - The vertex FROM
     * \param w - The vertex TO
     * \param connection - The edge connection type
     * \param id - The edge connection ID
     * \param weight - The edge optional weight
     * \param label - The edge optional label
     * \param maxCapacity - The edge optional max capacity
     * \param minCapacity - The edge optional min capacity
     */
    Edge(id_type v = 0,
        id_type w = 0,
        Connection connection = Connection::Bidirectional,
        const utility::Optional<id_type> &id = {},
        const utility::Optional<number_t> &weight = {},
        const utility::Optional<string_t> &label = {},
        const utility::Optional<number_t> &maxCapacity = {},
        const utility::Optional<number_t> &minCapacity = {});

    // Move is dangerous for this type
    Edge(const Edge&) = default;
    Edge &operator=(const Edge&) = default;
};
}

#endif // EGLI_EDGE_H_INCLUDED
