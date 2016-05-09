/*! \brief Function caller class and makeFunction()
 *
 * \file Function.h
 * \author Patrick Champion
 * \date 27.04.2016
 */

#ifndef EGLI_FUNCTION_H_INCLUDED
#define EGLI_FUNCTION_H_INCLUDED

#include "detail/FunctionImpl.h"

namespace egli
{
/*! \brief FunctionCaller abstract base class type
 */
using FunctionCaller = detail::FunctionCallerImpl;

/*! \brief Create a FunctionCaller from a function
 *
 * \param func - the function to wrap
 * \return The new FunctionCaller object
 *
 * \note The returned pointer must be explicitly deleted
 */
template<typename FunctionT>
FunctionCaller* makeFunction(FunctionT func)
{
    return detail::makeFunctionImpl(func);
}
} // namespace egli

#endif // EGLI_FUNCTION_H_INCLUDED
