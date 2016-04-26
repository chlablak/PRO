/*! \brief Edge structure
 *
 * \file Edge.cpp
 * \author Patrick Champion
 * \date 26.04.2016
 */

#include <string>

#include "Edge.h"
#include "Number.h"

egli::Edge::Edge(detail::id_type id,
    const utility::Optional<detail::RealType<detail::Type::Number>::type> &weight,
    const utility::Optional<detail::RealType<detail::Type::String>::type> &label,
    const utility::Optional<detail::RealType<detail::Type::Number>::type> &maxCapacity,
    const utility::Optional<detail::RealType<detail::Type::Number>::type> &minCapacity) :
        id(id),
        weight(weight),
        label(label),
        maxCapacity(maxCapacity),
        minCapacity(minCapacity)
{}
