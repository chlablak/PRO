/*! \brief Heterogenous dynamic array class
 *
 * \file Array.cpp
 * \author Patrick Champion
 * \date 26.04.2016
 */

#include "Array.h"
#include "Edge.h"
#include "Number.h"
#include "Vertex.h"

// Quick writing
#define EGLI_ARRAY_SWITCH_DELETE_CASE(E, elem) \
    case detail::Type::E: \
        delete static_cast<detail::RealType<detail::Type::E>::type*>(elem.ptr);\
        break;

egli::Array::Array() :
    elements() // avoid warning -Weffc++
{}

egli::Array::~Array()
{
    for (Element &element : elements) {
        switch (element.type) {
            EGLI_ARRAY_SWITCH_DELETE_CASE(Array, element)
            EGLI_ARRAY_SWITCH_DELETE_CASE(Boolean, element)
            EGLI_ARRAY_SWITCH_DELETE_CASE(Edge, element)
            EGLI_ARRAY_SWITCH_DELETE_CASE(Float, element)
            //EGLI_ARRAY_SWITCH_DELETE_CASE(Graph, element)
            EGLI_ARRAY_SWITCH_DELETE_CASE(Integer, element)
            EGLI_ARRAY_SWITCH_DELETE_CASE(Number, element)
            EGLI_ARRAY_SWITCH_DELETE_CASE(String, element)
            EGLI_ARRAY_SWITCH_DELETE_CASE(Vertex, element)
        }
    }
}

size_t egli::Array::size() const
{
    return elements.size();
}

egli::detail::Type egli::Array::typeOf(size_t i) const
{
    if (i >= size())
        throw Exception("Index out of range", "egli::Array::typeOf");

    return elements[i].type;
}

// not needed anymore
#undef EGLI_ARRAY_SWITCH_DELETE_CASE
