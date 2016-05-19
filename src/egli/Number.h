/*! \brief Number class (wrap Integer and Float)
 *
 * \file Number.h
 * \author Patrick Champion
 * \date 25.04.2016
 */

#ifndef EGLI_NUMBER_H_INCLUDED
#define EGLI_NUMBER_H_INCLUDED

#include "Type.h"
#include "detail/RealType.h"
#include "../utility/Optional.h"

namespace egli
{
/*! \brief Number class
 */
class Number
{
public:

    // Useful typedefs
    using float_t = detail::RealType<Type::Float>::type;

    /*! \brief Constructor
     *
     * \param value
     */
    Number(float_t value = static_cast<float_t>(0));

    /*! \brief Return the value as a float
     *
     * \return The contained value
     */
    operator float_t() const;

    /*! \brief Return a reference to the value
     *
     * \return The contained value
     */
    operator float_t&();

    /*! \brief Get the value as type T
     *
     * \return The contained value
     */
    template<typename T>
    T as() const;

    /*! \brief Is the number an int ?
     *
     * \return true if the contained value is an int
     */
    bool isInteger() const;

    /*! \brief Is the number a float ?
     *
     * \return true if the contained value is a float
     */
    bool isFloat() const;

private:

    float_t value;
};
} // namespace egli

template<typename T>
T egli::Number::as() const
{
    return value;
}

#endif // EGLI_NUMBER_H_INCLUDED
