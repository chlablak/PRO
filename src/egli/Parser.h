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

#include "detail/Statement.h"

namespace egli
{
// forward declaration to speed up the compilation
// (because detail::Grammar use Boost and is very "big")
namespace detail
{
template<typename>
struct Grammar;
}

class Parser
{
public:

    /*! \brief Constructor
     */
    Parser();

    /*! \brief Destructor
     */
    ~Parser();

    // detail::Grammar is not copyable
    Parser(const Parser&) = delete;
    Parser &operator=(const Parser&) = delete;

    /*! \brief Parse the buffer and return the statement
     *
     * \param buffer - string to be parsed
     * \return the constructed egli::detail::Statement
     *
     * \throw egli::Exception if parsing fails
     */
    detail::Statement parse(const std::string &buffer);

private:

    // data member
    detail::Grammar<std::string::const_iterator> *grammar;
};
} // namespace egli

#endif // EGLI_PARSER_H_INCLUDED
