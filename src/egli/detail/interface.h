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
void interfaceBasics(FunctionTable &table);

void interfaceBuiltins(FunctionTable &table);

void interfaceAlgorithms(FunctionTable &table);
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_INTERFACE_H_INCLUDED
