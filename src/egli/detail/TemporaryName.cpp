/*! \brief Generate temporary names
 *
 * \file TemporaryName.cpp
 * \author Patrick Champion
 * \date 26.04.2016
 */

#include <sstream>
#include <iomanip>

#include "TemporaryName.h"

egli::detail::TemporaryName::TemporaryName() :
    levels() // avoid warning -Weffc++
{
    enter();
}

void egli::detail::TemporaryName::enter()
{
    levels.push(0);
}

void egli::detail::TemporaryName::leave()
{
    levels.pop();
    if(levels.empty())
        enter();
}

std::string egli::detail::TemporaryName::next()
{
    std::ostringstream oss;
    oss << prefix()
        << std::setfill('0') << std::setw(width) << levels.top()++;
    return oss.str();
}

std::string egli::detail::TemporaryName::prefix() const
{
    std::ostringstream oss;
    oss << '_' << std::setfill('0') << std::setw(width) << (levels.size() - 1)
        << '_';
    return oss.str();
}

void egli::detail::TemporaryName::reset()
{
    while(!levels.empty())
        levels.pop();
    enter();
}
