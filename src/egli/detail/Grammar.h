/*! \brief Grammar used by the Parser
 *
 * \file Grammar.h
 * \author Patrick Champion
 * \date 19.04.2016
 *
 */

#ifndef EGLI_DETAIL_GRAMMAR_H_INCLUDED
#define EGLI_DETAIL_GRAMMAR_H_INCLUDED

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>

#include "Statement.h"

namespace egli
{
namespace detail
{
template<typename Iterator>
struct Grammar :
    boost::spirit::qi::grammar<Iterator, Statement()>
{
    /*! \brief Constructor
     *
     */
    Grammar() :
        Grammar::base_type(statement, "statement")
    {
        // Acces to boost features
        using boost::spirit::qi::uint_;
        using boost::spirit::qi::float_;
        using boost::spirit::qi::ascii::char_;
        using boost::spirit::qi::_val;
        using boost::spirit::qi::_1;
        using boost::spirit::qi::lit;
        using boost::spirit::qi::lexeme;
        using boost::phoenix::bind;

        statement.name("statement");
    }

    // data member
    boost::spirit::qi::rule<Iterator, Statement()> statement; // main rule
    boost::spirit::qi::rule<Iterator, Statement()> functionCall;
    boost::spirit::qi::rule<Iterator, Statement()> assignation;
    boost::spirit::qi::rule<Iterator, std::vector<Statement>()> parameterList;
    boost::spirit::qi::rule<Iterator, Statement()> parameter;
    boost::spirit::qi::rule<Iterator, Statement()> indexedArray;
    boost::spirit::qi::rule<Iterator, Statement()> arrayRecord;
    boost::spirit::qi::rule<Iterator, Statement()> constant;
    boost::spirit::qi::rule<Iterator, Statement()> complexConstant;
    boost::spirit::qi::rule<Iterator, Statement()> graphRecord;
    boost::spirit::qi::rule<Iterator, Statement()> edgeRecord;
    boost::spirit::qi::rule<Iterator, Statement()> vertexRecord;
    boost::spirit::qi::rule<Iterator, std::vector<std::string>()> graphInfo;
    boost::spirit::qi::rule<Iterator, std::vector<std::string>()> edgeInfo;
    boost::spirit::qi::rule<Iterator, std::vector<std::string>()> vertexInfo;
    boost::spirit::qi::rule<Iterator, std::string()> connection;
    boost::spirit::qi::rule<Iterator, std::string()> simpleConstant;
    boost::spirit::qi::rule<Iterator, std::string()> variable;
    boost::spirit::qi::rule<Iterator, std::string()> identifier;
    boost::spirit::qi::rule<Iterator, std::string()> stringLitteral;
    boost::spirit::qi::rule<Iterator, std::string()> letter;
    boost::spirit::qi::rule<Iterator, std::string()> boolean;
    boost::spirit::qi::rule<Iterator, std::string()> number;
    boost::spirit::qi::rule<Iterator, std::string()> sign;
};
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_GRAMMAR_H_INCLUDED
