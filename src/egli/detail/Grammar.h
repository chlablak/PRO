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
    Grammar();

    // boost::spirit::qi::grammar is not copyable
    Grammar(const Grammar&) = delete;
    Grammar &operator=(const Grammar&) = delete;

    // Avoid long type typing
    template<typename T>
    using rule = boost::spirit::qi::rule<Iterator, T>;

    // data members
    std::string error;              // error message
    rule<Statement()> start;        // starting rule
    rule<Statement()> statement;
    rule<Statement()> functionCall;
    rule<Statement()> assignation;
    rule<Statement()> graphAdd;
    rule<Statement()> graphSub;
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
    rule<Statement()> digitConstant;
    rule<Statement()> variable;
    rule<std::string()> identifier;
    rule<Statement()> stringConstant;
    rule<Statement()> booleanConstant;
    rule<Statement()> numberConstant;
    rule<Statement()> floatConstant;
};
} // namespace detail
} // namespace egli

template<typename Iterator>
egli::detail::Grammar<Iterator>::Grammar() :
    Grammar::base_type(start)
{
    // Access to boost features
    using boost::spirit::qi::int_;          // int
    using boost::spirit::qi::uint_;         // unsigned int
    using boost::spirit::qi::float_;        // float
    using boost::spirit::qi::ascii::char_;  // char
    using boost::spirit::qi::ascii::digit;  // matchs std::isdigit
    using boost::spirit::qi::ascii::alpha;  // matchs std::isalpha
    using boost::spirit::qi::ascii::alnum;  // matchs std::alnum
    using boost::spirit::qi::ascii::string; // string
    using boost::spirit::qi::_val;          // return attribute placeholder
    using boost::spirit::qi::_1;            // parser attribute placeholder
    using boost::spirit::qi::_2;            // parser attribute placeholder
    using boost::spirit::qi::_3;            // parser attribute placeholder
    using boost::spirit::qi::_4;            // parser attribute placeholder
    using boost::spirit::qi::lit;           // consume char*
    using boost::spirit::qi::eps;           // pre/post actions
    using boost::spirit::qi::attr;          // for default value
    using boost::spirit::qi::omit;          // ignore attribute type
    using boost::spirit::qi::as_string;     // cast to std::string
    using boost::spirit::qi::on_error;      // error handling
    using boost::spirit::qi::fail;          // error behavior
    using boost::phoenix::bind;             // bind members
    using boost::phoenix::push_back;        // push back in a vector
    using boost::phoenix::construct;        // call a constructor

    /* Define the rules and give them a name */
    /* ------------------------------------- */

    // Starting rule
    start %= eps > statement;

    // Autorised statements
    statement.name("statement");
    statement %= ( functionCall | assignation | graphAdd | graphSub ) > ';';

    // Function call
    functionCall.name("functionCall");
    functionCall = eps[_val = construct<Statement>()]
        >> identifier[bind(&Statement::value, _val) = _1]
        >> parameterList[bind(&Statement::parameters, _val) = _1]
        >> eps[bind(&Statement::type, _val) = Statement::Type::Function];

    // Variable declaration/assignation
    assignation.name("assignation");
    assignation = eps[_val = construct<Statement>()]
        >> identifier[bind(&Statement::value, _val) = _1]
        >> '='
        > parameter[push_back(bind(&Statement::parameters, _val), _1)]
        >> eps[bind(&Statement::type, _val) = Statement::Type::Assignation];

    // operator+= for Graph
    graphAdd.name("graphAdd");
    graphAdd = eps[_val = construct<Statement>()]
        >> variable[push_back(bind(&Statement::parameters, _val), _1)]
        >> "+="
        > parameter[push_back(bind(&Statement::parameters, _val), _1)]
        >> eps[bind(&Statement::value, _val) = "__graph_add"]
        >> eps[bind(&Statement::type, _val) = Statement::Type::Function];

    // operator-= for Graph
    graphSub.name("graphSub");
    graphSub = eps[_val = construct<Statement>()]
        >> variable[push_back(bind(&Statement::parameters, _val), _1)]
        >> "-="
        > parameter[push_back(bind(&Statement::parameters, _val), _1)]
        >> eps[bind(&Statement::value, _val) = "__graph_sub"]
        >> eps[bind(&Statement::type, _val) = Statement::Type::Function];

    // Function parameters
    parameterList.name("parameterList");
    parameterList %= '(' >> ((parameter % ',') | eps) > ')';

    // Parameters
    parameter.name("parameter");
    parameter %= functionCall | constant;

    // Indexed array
    indexedArray.name("indexedArray");
    indexedArray = eps[_val = construct<Statement>()]
        >> variable[push_back(bind(&Statement::parameters, _val), _1)]
        >> '['
        > digitConstant[push_back(bind(&Statement::parameters, _val), _1)]
        > ']'
        >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
        >> eps[bind(&Statement::value, _val) = "__array_get"];

    // Array record
    arrayRecord.name("arrayRecord");
    arrayRecord = eps[_val = construct<Statement>()]
        >> '['
        > ((parameter % ',')[bind(&Statement::parameters, _val) = _1] | eps)
        > ']'
        >> eps[bind(&Statement::type, _val) = Statement::Type::Array];

    // Constants
    constant.name("constant");
    constant %= complexConstant | simpleConstant;

    // Complex constants
    complexConstant.name("complexConstant");
    complexConstant %= indexedArray | arrayRecord | graphRecord | edgeRecord
        | vertexRecord;

    // Graph record
    graphRecord.name("graphRecord");
    graphRecord = eps[_val = construct<Statement>()]
        >> '{'
        > ((
            (graphInfo % ',')[push_back(bind(&Statement::parameters, _val),
                construct<Statement>(Statement::Type::Array, "", _1))]
        )|(
            lit('#')
            > digitConstant[push_back(bind(&Statement::parameters, _val), _1)]
            >> (*(',' > graphInfo))[push_back(bind(&Statement::parameters, _val),
                construct<Statement>(Statement::Type::Array, "", _1))]
        )|(
            eps[push_back(bind(&Statement::parameters, _val),
                construct<Statement>(Statement::Type::Array))]
        ))
        > '}'
        >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
        >> eps[bind(&Statement::value, _val) = "__graph_create"];

    // Edge record
    edgeRecord.name("edgeRecord");
    edgeRecord %= '(' >> edgeInfo > ')';

    // Vertex record
    vertexRecord.name("vertexRecord");
    vertexRecord %= '(' >> vertexInfo > ')';

    // Graph infos
    graphInfo.name("graphInfo");
    graphInfo %= edgeInfo | vertexInfo;

    // Edge info
    edgeInfo.name("edgeInfo");
    edgeInfo = eps[_val = construct<Statement>()]
        >> connection[bind(&Statement::parameters, _val) = _1]
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

    // Vertex info
    vertexInfo.name("vertexInfo");
    vertexInfo = eps[_val = construct<Statement>()]
        >> digitConstant[push_back(bind(&Statement::parameters, _val), _1)]
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

    // Edge connection
    connection.name("connection");
    connection = digitConstant[push_back(_val, _1)]
        >> (string("<-") | string("--") | string("->"))[push_back(_val,
            construct<Statement>(Statement::ConstantType::String, _1))]
        > digitConstant[push_back(_val, _1)];

    // Simple constants
    simpleConstant.name("simpleConstant");
    simpleConstant %= negation | booleanConstant | variable | numberConstant
        | stringConstant;

    // Negate function
    negation.name("negation");
    negation = eps[_val = construct<Statement>()]
        >> '-' >> parameter[push_back(bind(&Statement::parameters, _val), _1)]
        >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
        >> eps[bind(&Statement::value, _val) = "__negate"];

    // Integer constant
    digitConstant.name("digitConstant");
    digitConstant = eps[_val = construct<Statement>()]
        >> as_string[+digit][bind(&Statement::value, _val) = _1]
        >> eps[bind(&Statement::type, _val) = Statement::Type::Constant]
        >> eps[bind(&Statement::constantType, _val) = Statement::ConstantType::Integer];

    // Variable
    variable.name("variable");
    variable = eps[_val = construct<Statement>()]
        >> identifier[bind(&Statement::value, _val) = _1]
        >> eps[bind(&Statement::type, _val) = Statement::Type::Variable];

    // Identifier
    identifier.name("identifier");
    identifier %= alpha >> *(alnum | char_('_'));

    // String constant
    stringConstant.name("stringConstant");
    stringConstant = eps[_val = construct<Statement>()]
        >> '"'
        > as_string[+(char_ - '"')][bind(&Statement::value, _val) = _1]
        > '"'
        >> eps[bind(&Statement::type, _val) = Statement::Type::Constant]
        >> eps[bind(&Statement::constantType, _val) = Statement::ConstantType::String];

    // Boolean constant
    booleanConstant.name("booleanConstant");
    booleanConstant = eps[_val = construct<Statement>()]
        >> (string("True") | string("False"))[bind(&Statement::value, _val) = _1]
        >> eps[bind(&Statement::type, _val) = Statement::Type::Constant]
        >> eps[bind(&Statement::constantType, _val) = Statement::ConstantType::Boolean];

    // Number constant
    numberConstant.name("numberConstant");
    numberConstant %= floatConstant | digitConstant;

    // Float constant
    floatConstant.name("floatConstant");
    floatConstant = eps[_val = construct<Statement>()]
        >> as_string[+digit >> char_('.') > +digit][bind(&Statement::value, _val) = _1]
        >> eps[bind(&Statement::type, _val) = Statement::Type::Constant]
        >> eps[bind(&Statement::constantType, _val) = Statement::ConstantType::Float];

    // On fail, set the error message
    on_error<fail>(
        start,
        boost::phoenix::ref(error)
            = construct<std::string>(_1, _3)
            + "!>"
            + construct<std::string>(_3, _2)
            + " [expecting:"
            + bind(&boost::spirit::info::tag, _4)
            + "]"
    );
}

#endif // EGLI_DETAIL_GRAMMAR_H_INCLUDED
