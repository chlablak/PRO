/*! \brief Built-in functions to interface
 *
 * \file builtins.h
 * \author Patrick Champion
 * \date 03.05.2016
 */

#ifndef EGLI_DETAIL_INTERFACE_BUILTINS_H_INCLUDED
#define EGLI_DETAIL_INTERFACE_BUILTINS_H_INCLUDED

#include "../RealType.h"

namespace egli
{
namespace detail
{
namespace builtins
{
/*! \brief Get the String representation of a variable
 *
 * \param var
 * \return The String representation of var
 *
 * \note Declined in multiple version, one for each Type
 */
RealType<Type::String>::type toString_a(RealType<Type::Array>::cref var);
RealType<Type::String>::type toString_b(RealType<Type::Boolean>::cref var);
RealType<Type::String>::type toString_e(RealType<Type::Edge>::cref var);
RealType<Type::String>::type toString_f(RealType<Type::Float>::cref var);
//RealType<Type::String>::type toString_g(RealType<Type::Graph>::cref var);
RealType<Type::String>::type toString_i(RealType<Type::Integer>::cref var);
RealType<Type::String>::type toString_n(RealType<Type::Number>::cref var);
RealType<Type::String>::type toString_s(RealType<Type::String>::cref var);
RealType<Type::String>::type toString_v(RealType<Type::Vertex>::cref var);
} // namespace builtins
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_INTERFACE_BUILTINS_H_INCLUDED
