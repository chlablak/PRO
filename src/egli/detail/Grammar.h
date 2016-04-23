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
        using boost::spirit::qi::int_;         // int
        using boost::spirit::qi::uint_;         // unsigned int
        using boost::spirit::qi::float_;        // float
        using boost::spirit::qi::ascii::char_;  // char
        using boost::spirit::qi::ascii::string; // string
        using boost::spirit::qi::_val;          // return attribute placeholder
        using boost::spirit::qi::_1;            // parser attribute placeholder
        using boost::spirit::qi::lit;           // consume char*
        using boost::spirit::qi::eps;           // pre/post actions
        using boost::spirit::qi::attr;          // for default value
        using boost::spirit::qi::omit;          // ignore attribute type
        using boost::spirit::qi::as_string;     // cast to std::string
        using boost::phoenix::bind;             // bind members
        using boost::phoenix::push_back;        // push back in a vector
        using boost::phoenix::construct;        // call a constructor

        statement.name("statement");
        statement %= ( functionCall | assignation ) > ';';

        functionCall.name("functionCall");
        functionCall = identifier[bind(&Statement::value, _val) = _1]
            >> parameterList[bind(&Statement::parameters, _val) = _1]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Function];

        assignation.name("assignation");
        assignation = identifier[bind(&Statement::value, _val) = _1]
            >> '='
            > parameter[push_back(bind(&Statement::parameters, _val), _1)]
            > eps[bind(&Statement::type, _val) = Statement::Type::Assignation];

        parameterList.name("parameterList");
        parameterList %= ('(' >> (parameter % ',') > ')')
            | (lit("()") >> attr(construct<std::vector<Statement>>()));

        parameter.name("parameter");
        parameter %= functionCall | constant;

        indexedArray.name("indexedArray");
        indexedArray = variable[push_back(bind(&Statement::parameters, _val), _1)]
            >> '['
            > uintConstant[push_back(bind(&Statement::parameters, _val), _1)]
            > ']'
            >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
            >> eps[bind(&Statement::value, _val) = "__array_get"];

        arrayRecord.name("arrayRecord");
        arrayRecord = '['
            > (parameter % ',')[bind(&Statement::parameters, _val) = _1]
            > ']'
            >> eps[bind(&Statement::type, _val) = Statement::Type::Array];

        constant.name("constant");
        constant %= complexConstant | simpleConstant;

        complexConstant.name("complexConstant");
        complexConstant %= indexedArray | arrayRecord | graphRecord | edgeRecord | vertexRecord;

        graphRecord.name("graphRecord");
        graphRecord = ((
                   '{'
                > (graphInfo % ',')[push_back(bind(&Statement::parameters, _val),
                                               construct<Statement>(Statement::Type::Array, "", _1))]
                > '}'
            )|(
                   '{'
                > lit('#') >> uintConstant[push_back(bind(&Statement::parameters, _val), _1)]
                > (*(',' >> graphInfo))[push_back(bind(&Statement::parameters, _val),
                                                   construct<Statement>(Statement::Type::Array, "", _1))]
                > '}'
            ))
            >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
            >> eps[bind(&Statement::value, _val) = "__graph_create"];

        edgeRecord.name("edgeRecord");
        edgeRecord %= '(' >> edgeInfo > ')';

        vertexRecord.name("vertexRecord");
        vertexRecord %= '(' >> vertexInfo > ')';

        graphInfo.name("graphInfo");
        graphInfo %= edgeInfo | vertexInfo;

        edgeInfo.name("edgeInfo");
        edgeInfo = connection[bind(&Statement::parameters, _val) = _1]
            >> ((':' >> numberConstant) | omit[-char_(':')] >> attr(Statement()))
                [push_back(bind(&Statement::parameters, _val), _1)]
            >> ((':' >> stringConstant) | omit[-char_(':')] >> attr(Statement()))
                [push_back(bind(&Statement::parameters, _val), _1)]
            >> ((':' >> numberConstant) | omit[-char_(':')] >> attr(Statement()))
                [push_back(bind(&Statement::parameters, _val), _1)]
            >> ((':' >> numberConstant) | omit[-char_(':')] >> attr(Statement()))
                [push_back(bind(&Statement::parameters, _val), _1)]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
            >> eps[bind(&Statement::value, _val) = "__edge_create"];

        vertexInfo.name("vertexInfo");
        vertexInfo = uintConstant[push_back(bind(&Statement::parameters, _val), _1)]
            >> ((':' >> stringConstant) | omit[-char_(':')] >> attr(Statement()))
                [push_back(bind(&Statement::parameters, _val), _1)]
            >> ((':' >> numberConstant) | omit[-char_(':')] >> attr(Statement()))
                [push_back(bind(&Statement::parameters, _val), _1)]
            >> ((':' >> numberConstant) | omit[-char_(':')] >> attr(Statement()))
                [push_back(bind(&Statement::parameters, _val), _1)]
            >> ((':' >> numberConstant) | omit[-char_(':')] >> attr(Statement()))
                [push_back(bind(&Statement::parameters, _val), _1)]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
            >> eps[bind(&Statement::value, _val) = "__vertex_create"];

        connection.name("connection");
        connection = uintConstant[push_back(_val, _1)]
            >> (string("<-") | string("--") | string("->"))
                [push_back(_val, construct<Statement>(Statement::Type::Constant, _1))]
            > uintConstant[push_back(_val, _1)];

        simpleConstant.name("simpleConstant");
        simpleConstant %= negation | booleanConstant | variable | numberConstant | stringConstant;

        negation.name("negation");
        negation = '-' >> parameter[push_back(bind(&Statement::parameters, _val), _1)]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
            >> eps[bind(&Statement::value, _val) = "__negate"];

        uintConstant.name("uintConstant");
        intConstant = as_string[uint_][bind(&Statement::value, _val) = _1]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Constant];

        variable.name("variable");
        variable = identifier[bind(&Statement::value, _val) = _1]
            >> eps[bind(&Statement::type, _val) == Statement::Type::Variable];

        identifier.name("identifier");
        identifier %= letter >> *(letter | digit | char_('_'));

        stringConstant.name("stringConstant");
        stringConstant = '"'
            > as_string[+(char_ - '"')][bind(&Statement::value, _val) = _1]
            > '"'
            >> eps[bind(&Statement::type, _val) == Statement::Type::Constant];

        letter.name("letter");
        letter %= char_('a', 'z') | char_('A', 'Z');

        booleanConstant.name("booleanConstant");
        booleanConstant = (string("True") | string("False"))[bind(&Statement::value, _val) = _1]
            >> eps[bind(&Statement::type, _val) == Statement::Type::Constant];

        numberConstant.name("numberConstant");
        numberConstant = intConstant | floatConstant;

        intConstant.name("intConstant");
        intConstant = as_string[int_][bind(&Statement::value, _val) = _1]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Constant];

        floatConstant.name("floatConstant");
        floatConstant = as_string[float_][bind(&Statement::value, _val) = _1]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Constant];

        digit.name("digit");
        digit %= char_('0', '9');

        boost::spirit::qi::on_error<boost::spirit::qi::fail>(
            statement,
            boost::phoenix::ref(error)
                = construct<std::string>(boost::spirit::qi::_1, boost::spirit::qi::_3)
                + "!>"
                + construct<std::string>(boost::spirit::qi::_3, boost::spirit::qi::_2)
                + " [expecting:"
                + bind(&boost::spirit::info::tag, boost::spirit::qi::_4)
                + "]"
        );
    }

    template<typename T>
    using rule = boost::spirit::qi::rule<Iterator, T>;

    // data member
    rule<Statement()> statement;
    rule<Statement()> functionCall;
    rule<Statement()> assignation;
    rule<std::vector<Statement>()> parameterList;
    rule<Statement()> parameter;
    rule<Statement()> indexedArray;
    rule<Statement()> arrayRecord;
    rule<Statement()> constant;
    rule<Statement()> complexConstant;
    rule<Statement()> graphRecord;
    rule<Statement()> edgeRecord;
    rule<Statement()> vertexRecord;
    rule<Statement()> graphInfo;
    rule<Statement()> edgeInfo;
    rule<Statement()> vertexInfo;
    rule<std::vector<Statement>()> connection;
    rule<Statement()> simpleConstant;
    rule<Statement()> negation;
    rule<Statement()> uintConstant;
    rule<Statement()> variable;
    rule<std::string()> identifier;
    rule<Statement()> stringConstant;
    rule<char()> letter;
    rule<Statement()> booleanConstant;
    rule<Statement()> numberConstant;
    rule<Statement()> intConstant;
    rule<Statement()> floatConstant;
    rule<char()> digit;

    std::string error;
};
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_GRAMMAR_H_INCLUDED
