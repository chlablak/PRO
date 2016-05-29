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
/*! \brief Save the Graph to a file
 *
 * \param g - The Graph to save
 * \param file - The file name
 * \return true on success
 *
 * \throw Exception if there is a error
 */
RealType<Type::Boolean>::type
    save(RealType<Type::Graph>::cref g, RealType<Type::String>::cref file);

/*! \brief Load a Graph from a file
 *
 * \param file - The file name
 * \return The loaded Graph
 *
 * \throw Exception if there is a error
 */
RealType<Type::Graph>::type load(RealType<Type::String>::cref file);

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
RealType<Type::String>::type toString_g(RealType<Type::Graph>::cref var);
RealType<Type::String>::type toString_i(RealType<Type::Integer>::cref var);
RealType<Type::String>::type toString_n(RealType<Type::Number>::cref var);
RealType<Type::String>::type toString_s(RealType<Type::String>::cref var);
RealType<Type::String>::type toString_v(RealType<Type::Vertex>::cref var);

/*! \brief Get the String representation of a variable type
 *
 * \param var
 * \return The String representation of var's type
 *
 * \note Declined in multiple version, one for each Type
 */
RealType<Type::String>::type typeOf_a(RealType<Type::Array>::cref var);
RealType<Type::String>::type typeOf_b(RealType<Type::Boolean>::cref var);
RealType<Type::String>::type typeOf_e(RealType<Type::Edge>::cref var);
RealType<Type::String>::type typeOf_f(RealType<Type::Float>::cref var);
RealType<Type::String>::type typeOf_g(RealType<Type::Graph>::cref var);
RealType<Type::String>::type typeOf_i(RealType<Type::Integer>::cref var);
RealType<Type::String>::type typeOf_n(RealType<Type::Number>::cref var);
RealType<Type::String>::type typeOf_s(RealType<Type::String>::cref var);
RealType<Type::String>::type typeOf_v(RealType<Type::Vertex>::cref var);

/*! \brief Generate a random Erdos-Renyi Graph
 *
 * \param V - number of vertices
 * \param p - inclusion probability
 * \return A Erdos-Renyi Graph
 *
 * \throw Exception if V < 0 or if !(0 <= p <= 1)
 * \note If p == 1, return a complete graph (e.g. K10 if V == 10)
 * \note See http://icdt.tu-dortmund.de/proceedings/edbticdt2011proc/WebProceedings/papers/edbt/a30-nobari.pdf
 *       (algorithm 1)
 */
RealType<Type::Graph>::type originalErdosRenyi(RealType<Type::Integer>::cref V,
                                               RealType<Type::Float>::cref p);

/*! \brief Get the size of an Array
 *
 * \param var - The Array
 * \return The number of element in var
 */
RealType<Type::Integer>::type size_a(RealType<Type::Array>::cref var);

/*! \brief Get the size of a Graph
 *
 * \param var - The Graph
 * \return [0] => The number of Vertex
 *         [1] => The number of Edge
 */
RealType<Type::Array>::type size_g(RealType<Type::Graph>::cref var);
} // namespace builtins
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_INTERFACE_BUILTINS_H_INCLUDED
