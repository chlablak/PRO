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
    case Type::E: \
        delete static_cast<detail::RealType<Type::E>::type*>(elem.ptr);\
        break;

// Quick writing
#define EGLI_ARRAY_SWITCH_ADD_CASE(E, o, i) \
    case Type::E: \
        add(o.get<detail::RealType<Type::E>::type>(i)); \
        break;

egli::Array::Array() :
    elements() // avoid warning -Weffc++
{}

egli::Array::Array(const Array &a) :
    elements()
{
    for (size_t i = 0; i < a.size(); ++i) {
        switch(a.typeOf(i)) {
            EGLI_ARRAY_SWITCH_ADD_CASE(Array, a, i)
            EGLI_ARRAY_SWITCH_ADD_CASE(Boolean, a, i)
            EGLI_ARRAY_SWITCH_ADD_CASE(Edge, a, i)
            EGLI_ARRAY_SWITCH_ADD_CASE(Float, a, i)
            //EGLI_ARRAY_SWITCH_ADD_CASE(Graph, a, i)
            EGLI_ARRAY_SWITCH_ADD_CASE(Integer, a, i)
            EGLI_ARRAY_SWITCH_ADD_CASE(Number, a, i)
            EGLI_ARRAY_SWITCH_ADD_CASE(String, a, i)
            EGLI_ARRAY_SWITCH_ADD_CASE(Vertex, a, i)
        }
    }
}

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

egli::Array &egli::Array::operator=(const Array &a)
{
    // copy-and-swap idiom
    Array tmp(a);
    std::swap(elements, tmp.elements);
    return *this;
}

size_t egli::Array::size() const
{
    return elements.size();
}

egli::Type egli::Array::typeOf(size_t i) const
{
    if (i >= size())
        throw Exception("Index out of range", "egli::Array::typeOf");

    return elements[i].type;
}

// not needed anymore
#undef EGLI_ARRAY_SWITCH_DELETE_CASE
#undef EGLI_ARRAY_SWITCH_ADD_CASE
