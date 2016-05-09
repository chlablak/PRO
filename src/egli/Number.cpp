/*! \brief Number class
 *
 * \file Number.cpp
 * \author Patrick Champion
 * \date 25.04.2016
 */

#include <cmath>
#include <limits>

#include "Number.h"

egli::Number::Number(float_t value) :
    value(value)
{}

egli::Number::operator float_t() const
{
    return value;
}

egli::Number::operator float_t&()
{
    return value;
}

egli::Number::operator integer_t() const
{
    return value;
}

bool egli::Number::isInteger() const
{
    return std::abs(std::modf(value, nullptr))
        <= std::numeric_limits<float_t>::epsilon();
}

bool egli::Number::isFloat() const
{
    return !isInteger();
}
