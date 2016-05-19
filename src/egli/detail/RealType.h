/*! \brief Get the real type behind Type enum
 *
 * \file RealType.h
 * \author Patrick Champion
 * \date 25.04.2016
 */

#ifndef EGLI_DETAIL_REALTYPE_H_INCLUDED
#define EGLI_DETAIL_REALTYPE_H_INCLUDED

#include <string>

#include "../Type.h"

// Quick writing
#define EGLI_DETAIL_TYPES_DEF_REALTYPE(E, T) \
    template<> \
    struct RealType<Type::E> \
    { \
        using type = T; \
        using cref = const T&; \
    };

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
/*! \brief Get the real C++ type behind T
 *
 * \note Exemple: RealType<Type::Integer>::type -> int
 */
template<Type T>
struct RealType;

// Specialize RealType
EGLI_DETAIL_TYPES_DEF_REALTYPE(Array, Array)
EGLI_DETAIL_TYPES_DEF_REALTYPE(Boolean, bool)
EGLI_DETAIL_TYPES_DEF_REALTYPE(Edge, Edge)
EGLI_DETAIL_TYPES_DEF_REALTYPE(Float, float)
EGLI_DETAIL_TYPES_DEF_REALTYPE(Graph, GraphWrapper)
EGLI_DETAIL_TYPES_DEF_REALTYPE(Integer, int)
EGLI_DETAIL_TYPES_DEF_REALTYPE(Number, Number)
EGLI_DETAIL_TYPES_DEF_REALTYPE(String, std::string)
EGLI_DETAIL_TYPES_DEF_REALTYPE(Vertex, Vertex)
} // namespace detail
} // namespace egli

// Not needed anymore
#undef EGLI_DETAIL_TYPES_DEF_REALTYPE

#endif // EGLI_DETAIL_REALTYPE_H_INCLUDED
