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

#include <iostream>

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
        using boost::spirit::qi::lit;           // consume char*
        using boost::spirit::qi::eps;           // pre/post actions
        using boost::spirit::qi::attr;          // for default value
        using boost::spirit::qi::omit;          // ignore attribute type
        using boost::spirit::qi::as_string;     // cast to std::string
        using boost::phoenix::bind;             // bind members
        using boost::phoenix::push_back;        // push back in a vector
        using boost::phoenix::construct;        // call a constructor

        /* Define the rules and give them a name */
        /* ------------------------------------- */

        start %= eps > statement;

        statement.name("statement");
        statement %=eps[([](){std::cout<<"enter:statement"<<std::endl;})]>>( ( functionCall | assignation ) > ';' )>>eps[([](){std::cout<<"LEAVE:statement"<<std::endl;})];

        functionCall.name("functionCall");
        functionCall =eps[([](){std::cout<<"enter:functionCall"<<std::endl;})]>>( eps[_val = construct<Statement>()]
            >> identifier[bind(&Statement::value, _val) = _1]
            >> parameterList[bind(&Statement::parameters, _val) = _1]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Function] )>>eps[([](){std::cout<<"LEAVE:functionCall"<<std::endl;})];

        assignation.name("assignation");
        assignation =eps[([](){std::cout<<"enter:assignation"<<std::endl;})]>>( eps[_val = construct<Statement>()]
            >> identifier[bind(&Statement::value, _val) = _1]
            >> '='
            > parameter[push_back(bind(&Statement::parameters, _val), _1)]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Assignation] )>>eps[([](){std::cout<<"LEAVE:assignation"<<std::endl;})];

        parameterList.name("parameterList");
        parameterList %=eps[([](){std::cout<<"enter:parameterList"<<std::endl;})]>>( '(' >> ((parameter % ',') | eps) > ')' )>>eps[([](){std::cout<<"LEAVE:parameterList"<<std::endl;})];

        parameter.name("parameter");
        parameter %=eps[([](){std::cout<<"enter:parameter"<<std::endl;})]>>( functionCall | constant )>>eps[([](){std::cout<<"LEAVE:parameter"<<std::endl;})];

        indexedArray.name("indexedArray");
        indexedArray =eps[([](){std::cout<<"enter:indexedArray"<<std::endl;})]>>( eps[_val = construct<Statement>()]
            >> variable[push_back(bind(&Statement::parameters, _val), _1)]
            >> '['
            > digitConstant[push_back(bind(&Statement::parameters, _val), _1)]
            > ']'
            >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
            >> eps[bind(&Statement::value, _val) = "__array_get"] )>>eps[([](){std::cout<<"LEAVE:indexedArray"<<std::endl;})];

        arrayRecord.name("arrayRecord");
        arrayRecord =eps[([](){std::cout<<"enter:arrayRecord"<<std::endl;})]>>( eps[_val = construct<Statement>()]
            >> '['
            > ((parameter % ',')[bind(&Statement::parameters, _val) = _1] | eps)
            > ']'
            >> eps[bind(&Statement::type, _val) = Statement::Type::Array] )>>eps[([](){std::cout<<"LEAVE:arrayRecord"<<std::endl;})];

        constant.name("constant");
        constant %=eps[([](){std::cout<<"enter:constant"<<std::endl;})]>>( complexConstant | simpleConstant )>>eps[([](){std::cout<<"LEAVE:constant"<<std::endl;})];

        complexConstant.name("complexConstant");
        complexConstant %=eps[([](){std::cout<<"enter:complexConstant"<<std::endl;})]>>( indexedArray | arrayRecord | graphRecord | edgeRecord | vertexRecord )>>eps[([](){std::cout<<"LEAVE:complexConstant"<<std::endl;})];

        graphRecord.name("graphRecord");
        graphRecord =eps[([](){std::cout<<"enter:graphRecord"<<std::endl;})]>>( eps[_val = construct<Statement>()]
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
                eps[push_back(bind(&Statement::parameters, _val), construct<Statement>(Statement::Type::Array))]
            ))
            > '}'
            >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
            >> eps[bind(&Statement::value, _val) = "__graph_create"] )>>eps[([](){std::cout<<"LEAVE:graphRecord"<<std::endl;})];

        edgeRecord.name("edgeRecord");
        edgeRecord %=eps[([](){std::cout<<"enter:edgeRecord"<<std::endl;})]>>( '(' >> edgeInfo > ')' )>>eps[([](){std::cout<<"LEAVE:edgeRecord"<<std::endl;})];

        vertexRecord.name("vertexRecord");
        vertexRecord %=eps[([](){std::cout<<"enter:vertexRecord"<<std::endl;})]>>( '(' >> vertexInfo > ')' )>>eps[([](){std::cout<<"LEAVE:vertexRecord"<<std::endl;})];

        graphInfo.name("graphInfo");
        graphInfo %=eps[([](){std::cout<<"enter:graphInfo"<<std::endl;})]>>( edgeInfo | vertexInfo )>>eps[([](){std::cout<<"LEAVE:graphInfo"<<std::endl;})];

        edgeInfo.name("edgeInfo");
        edgeInfo =eps[([](){std::cout<<"enter:edgeInfo"<<std::endl;})]>>( eps[_val = construct<Statement>()]
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
            >> eps[bind(&Statement::value, _val) = "__edge_create"] )>>eps[([](){std::cout<<"LEAVE:edgeInfo"<<std::endl;})];

        vertexInfo.name("vertexInfo");
        vertexInfo =eps[([](){std::cout<<"enter:vertexInfo"<<std::endl;})]>>( eps[_val = construct<Statement>()]
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
            >> eps[bind(&Statement::value, _val) = "__vertex_create"] )>>eps[([](){std::cout<<"LEAVE:vertexInfo"<<std::endl;})];

        connection.name("connection");
        connection =eps[([](){std::cout<<"enter:connection"<<std::endl;})]>>( digitConstant[push_back(_val, _1)]
            >> (string("<-") | string("--") | string("->"))
                [push_back(_val, construct<Statement>(Statement::Type::Constant, _1))]
            > digitConstant[push_back(_val, _1)] )>>eps[([](){std::cout<<"LEAVE:connection"<<std::endl;})];

        simpleConstant.name("simpleConstant");
        simpleConstant %=eps[([](){std::cout<<"enter:simpleConstant"<<std::endl;})]>>( negation | booleanConstant | variable | numberConstant | stringConstant )>>eps[([](){std::cout<<"LEAVE:simpleConstant"<<std::endl;})];

        negation.name("negation");
        negation =eps[([](){std::cout<<"enter:negation"<<std::endl;})]>>( eps[_val = construct<Statement>()]
            >> '-' >> parameter[push_back(bind(&Statement::parameters, _val), _1)]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Function]
            >> eps[bind(&Statement::value, _val) = "__negate"] )>>eps[([](){std::cout<<"LEAVE:negation"<<std::endl;})];

        digitConstant.name("digitConstant");
        digitConstant =eps[([](){std::cout<<"enter:digitConstant"<<std::endl;})]>>( eps[_val = construct<Statement>()]
            >> as_string[+digit][bind(&Statement::value, _val) = _1]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Constant] )>>eps[([](){std::cout<<"LEAVE:digitConstant"<<std::endl;})];

        variable.name("variable");
        variable =eps[([](){std::cout<<"enter:variable"<<std::endl;})]>>( eps[_val = construct<Statement>()]
            >> identifier[bind(&Statement::value, _val) = _1]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Variable] )>>eps[([](){std::cout<<"LEAVE:variable"<<std::endl;})];

        identifier.name("identifier");
        identifier %=eps[([](){std::cout<<"enter:identifier"<<std::endl;})]>>( alpha >> *(alnum | char_('_')) )>>eps[([](){std::cout<<"LEAVE:identifier"<<std::endl;})];

        stringConstant.name("stringConstant");
        stringConstant =eps[([](){std::cout<<"enter:stringConstant"<<std::endl;})]>>( eps[_val = construct<Statement>()]
            >> '"'
            > as_string[+(char_ - '"')][bind(&Statement::value, _val) = _1]
            > '"'
            >> eps[bind(&Statement::type, _val) = Statement::Type::Constant] )>>eps[([](){std::cout<<"LEAVE:stringConstant"<<std::endl;})];

        booleanConstant.name("booleanConstant");
        booleanConstant =eps[([](){std::cout<<"enter:booleanConstant"<<std::endl;})]>>( eps[_val = construct<Statement>()]
            >> (string("True") | string("False"))[bind(&Statement::value, _val) = _1]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Constant] )>>eps[([](){std::cout<<"LEAVE:booleanConstant"<<std::endl;})];

        numberConstant.name("numberConstant");
        numberConstant %=eps[([](){std::cout<<"enter:numberConstant"<<std::endl;})]>>( floatConstant | digitConstant )>>eps[([](){std::cout<<"LEAVE:numberConstant"<<std::endl;})];

        floatConstant.name("floatConstant");
        floatConstant =eps[([](){std::cout<<"enter:floatConstant"<<std::endl;})]>>( eps[_val = construct<Statement>()]
            >> as_string[+digit >> char_('.') > +digit][bind(&Statement::value, _val) = _1]
            >> eps[bind(&Statement::type, _val) = Statement::Type::Constant] )>>eps[([](){std::cout<<"LEAVE:floatConstant"<<std::endl;})];

        // On fail, set the error message
        boost::spirit::qi::on_error<boost::spirit::qi::fail>(
            start,
            boost::phoenix::ref(error)
                = construct<std::string>(boost::spirit::qi::_1, boost::spirit::qi::_3)
                + "!>"
                + construct<std::string>(boost::spirit::qi::_3, boost::spirit::qi::_2)
                + " [expecting:"
                + bind(&boost::spirit::info::tag, boost::spirit::qi::_4)
                + "]"
        );
    }

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
    rule<std::vector<Statement>()> parameterList;
    rule<Statement()> parameter;
    #warning TODO expression, +=, -+, -
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

#endif // EGLI_DETAIL_GRAMMAR_H_INCLUDED
