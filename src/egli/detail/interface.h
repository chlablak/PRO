/*! \brief Interface functions
 *
 * \file interface.h
 * \author Patrick Champion
 * \date 03.05.2016
 */

#ifndef EGLI_DETAIL_INTERFACE_H_INCLUDED
#define EGLI_DETAIL_INTERFACE_H_INCLUDED

#include "../FunctionTable.h"

namespace egli
{
namespace detail
{
/*! \brief Interface basics functions
 *
 * \param table - The functions table
 */
void interfaceBasics(FunctionTable &table);

/*! \brief Interface built-ins functions
 *
 * \param table - The functions table
 */
void interfaceBuiltins(FunctionTable &table);

/*! \brief Interface algorithms functions
 *
 * \param table - The functions table
 */
void interfaceAlgorithms(FunctionTable &table);
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_INTERFACE_H_INCLUDED
