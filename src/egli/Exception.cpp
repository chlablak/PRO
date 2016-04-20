/*! \brief Exception base class
 *
 * \file Exception.cpp
 * \author Patrick Champion
 * \date 20.04.2016
 *
 */

#include "Exception.h"

egli::Exception::Exception(const std::string &message,
                           const std::string &who,
                           const std::string &where) :
    std::runtime_error("error '" + message + "'"
                       + (where.empty()
                          ? (who.empty() ? "" : " (from '" + who + "')" )
                          : " (at '" + where + "'"
                            + (who.empty() ? ")" : " from '" + who + "')")))
{}

egli::Exception::~Exception()
{}
