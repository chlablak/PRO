/*! \brief Vertex structure
 *
 * \file Vertex.cpp
 * \author Patrick Champion
 * \date 26.04.2016
 */

#include <string>

#include "Vertex.h"
#include "Number.h"

egli::Vertex::Vertex(detail::id_type id,
    const utility::Optional<detail::RealType<detail::Type::String>::type> &label,
    const utility::Optional<detail::RealType<detail::Type::Number>::type> &weight,
    const utility::Optional<detail::RealType<detail::Type::Number>::type> &maxCapacity,
    const utility::Optional<detail::RealType<detail::Type::Number>::type> &minCapacity) :
        id(id),
        label(label),
        weight(weight),
        maxCapacity(maxCapacity),
        minCapacity(minCapacity)
{}
