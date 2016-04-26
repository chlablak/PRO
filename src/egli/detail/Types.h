/*! \brief Define the types used
 *
 * \file Types.h
 * \author Patrick Champion
 * \date 25.04.2016
 */

#ifndef EGLI_DETAIL_TYPES_H_INCLUDED
#define EGLI_DETAIL_TYPES_H_INCLUDED

#include <string>

// Quick writing
#define EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE(E, T) \
    template<> \
    struct RealType<Type::E> \
    { \
        using type = T; \
        using cref = const T&; \
    }; \
    template<> \
    struct EnumValue<T> \
    { \
        static constexpr Type value = Type::E; \
    };

namespace egli
{
// Forward declarations
class Number;
struct Vertex;
struct Edge;
class Array;

namespace detail
{
/*! \brief ID typedef
 */
using id_type = unsigned int;

/*! \brief Types enumeration
 */
enum class Type
{
    Array,
    Boolean,
    Edge,
    Float,
    Graph,
    Integer,
    Number,
    String,
    Vertex
};

/*! \brief Get the real C++ type behind T
 *
 * \note Exemple: RealType<Type::Integer>::type -> int
 * \note Exemple: RealType<Type::String>::cref -> const std::string&
 */
template<Type T>
struct RealType;

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

// Specialize RealType and EnumValue
EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE(Array, Array)
EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE(Boolean, bool)
EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE(Edge, Edge)
EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE(Float, float)
//EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE(Graph, )
EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE(Integer, int)
EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE(Number, Number)
EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE(String, std::string)
EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE(Vertex, Vertex)

#warning missing Graph type
} // namespace detail
} // namespace egli

// Not needed anymore
#undef EGLI_DETAIL_TYPES_DEF_REALTYPE_AND_ENUMVALUE

#endif // EGLI_DETAIL_TYPES_H_INCLUDED
