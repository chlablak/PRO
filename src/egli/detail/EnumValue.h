/*! \brief Get the Type enum value from a type
 *
 * \file EnumValue.h
 * \author Patrick Champion
 * \date 25.04.2016
 */

#ifndef EGLI_DETAIL_ENUMVALUE_H_INCLUDED
#define EGLI_DETAIL_ENUMVALUE_H_INCLUDED

#include <string>
#include <vector>

#include "../Type.h"
#include "../../utility/Optional.h"

// Quick writing
#define EGLI_DETAIL_TYPES_DEF_ENUMVALUE(E, T) \
    template<> \
    struct EnumValue<T> \
    { \
        static constexpr Type value = Type::E; \
    };

// Forward declaration
class IGraph; // workaround

namespace egli
{
// Forward declarations
class Number;
struct Vertex;
struct Edge;
class Array;
class GraphWrapper;

namespace detail
{
/*! \brief Get the enumeration value behind T
 *
 * \note Exemple: EnumValue<int>::value -> Type::Integer
 */
template<typename T>
struct EnumValue;

// Remove reference
template<typename T>
struct EnumValue<T&> :
    EnumValue<T>
{};

// Remove const
template<typename T>
struct EnumValue<const T> :
    EnumValue<T>
{};

// Remove Optional
template<typename T>
struct EnumValue<utility::Optional<T>> :
    EnumValue<T>
{};

// Specialize RealType and EnumValue
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Array, Array)
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Boolean, bool)
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Edge, Edge)
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Float, float)
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Float, double) // workaround
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Graph, GraphWrapper)
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Graph, IGraph*) // workaround
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Graph, const IGraph*) // workaround
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Integer, int)
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Integer, id_type) // workaround
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Number, Number)
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(String, std::string)
EGLI_DETAIL_TYPES_DEF_ENUMVALUE(Vertex, Vertex)
} // namespace detail
} // namespace egli

// Not needed anymore
#undef EGLI_DETAIL_TYPES_DEF_ENUMVALUE

#endif // EGLI_DETAIL_ENUMVALUE_H_INCLUDED
