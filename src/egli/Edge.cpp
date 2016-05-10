/*! \brief Edge structure
 *
 * \file Edge.cpp
 * \author Patrick Champion
 * \date 26.04.2016
 */

#include <string>

#include "Edge.h"
#include "Number.h"

egli::Edge::Edge(id_type v,
    id_type w,
    Connection connection,
    const utility::Optional<id_type> &id,
    const utility::Optional<number_t> &weight,
    const utility::Optional<string_t> &label,
    const utility::Optional<number_t> &maxCapacity,
    const utility::Optional<number_t> &minCapacity) :
        v(v),
        w(w),
        connection(connection),
        id(id),
        weight(weight),
        label(label),
        maxCapacity(maxCapacity),
        minCapacity(minCapacity)
{}
