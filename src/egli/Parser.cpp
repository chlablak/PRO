/*! \brief Parser validation
 *
 * \file Parser.cpp
 * \author Patrick Champion
 * \date 20.04.2016
 */

#include <boost/spirit/include/qi.hpp>

#include "Parser.h"
#include "Exception.h"
#include "detail/Grammar.h"

egli::Parser::Parser() :
    grammar(new detail::Grammar<std::string::const_iterator>)
{}

egli::Parser::~Parser()
{
    delete grammar;
}

egli::Statement egli::Parser::parse(const std::string &buffer)
{
    // Access to boost features
    using boost::spirit::qi::parse;

    // Iterators on the buffer string
    std::string::const_iterator iter = buffer.begin();
    std::string::const_iterator end = buffer.end();

    // Let's parse using our grammar
    egli::Statement statement;
    bool success = parse(iter, end, *grammar, statement);

    // If the parsing failed, we throw an exception
    if (!success || iter != end)
        throw egli::Exception("parsing failed", "egli::Parser::parse", grammar->error);

    // All ok! Return the resulting Statement
    return statement;
}
