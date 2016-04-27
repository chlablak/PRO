/*! \brief Vertex structure
 *
 * \file Vertex.cpp
 * \author Patrick Champion
 * \date 26.04.2016
 */

#include <string>

#include "Vertex.h"
#include "Number.h"

egli::Vertex::Vertex(id_type id,
    const utility::Optional<string_t> &label,
    const utility::Optional<number_t> &weight,
    const utility::Optional<number_t> &maxCapacity,
    const utility::Optional<number_t> &minCapacity) :
        id(id),
        label(label),
        weight(weight),
        maxCapacity(maxCapacity),
        minCapacity(minCapacity)
{}
