/*! \brief Parser validation
 *
 * \file Parser.h
 * \author Patrick Champion
 * \date 19.04.2016
 *
 */

#ifndef EGLI_PARSER_H_INCLUDED
#define EGLI_PARSER_H_INCLUDED

#include <string>

#include "detail/Grammar.h"
#include "detail/Statement.h"

namespace egli
{
class Parser
{
public:

    /*! \brief Parse the buffer and return the statement
     *
     * \param buffer - string to be parsed
     * \return the constructed egli::detail::Statement
     *
     * \throw egli::Exception if parsing fails
     *
     */
    detail::Statement parse(const std::string &buffer) const;

private:

    // data member
    detail::Grammar<std::string::const_iterator> grammar;
};
} // namespace egli

#endif // EGLI_PARSER_H_INCLUDED
