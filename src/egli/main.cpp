/*! \brief Unary tests for EGLI interpreter
 *
 * \file main.cpp
 * \author Patrick Champion
 * \date 19.04.2016
 */

#include <iostream>
#include <string>
#include <cassert>

#include "egli.h"

#include "detail/Preprocessor.h"
#include "detail/interface.h"
#include "detail/interface/builtins.h"

using namespace std;

void print(ostream &os, egli::Statement const &s, size_t tab = 0)
{
    for (size_t i = 0; i < tab; ++i)
        os << " ";
    switch (s.type) {
        case egli::Statement::Type::Assignation: os << "Assignation"; break;
        case egli::Statement::Type::Array: os << "Array"; break;
        case egli::Statement::Type::Constant: os << "Constant"; break;
        case egli::Statement::Type::Function: os << "Function"; break;
        case egli::Statement::Type::None: os << "None"; break;
        case egli::Statement::Type::Variable: os << "Variable"; break;
    }
    os << "(\"" << s.value << "\"";
    if (s.type == egli::Statement::Type::Constant) {
        os << " ";
        switch (s.constantType) {
            case egli::Statement::ConstantType::Boolean: os << "Boolean"; break;
            case egli::Statement::ConstantType::Float: os << "Float"; break;
            case egli::Statement::ConstantType::Integer: os << "Integer"; break;
            case egli::Statement::ConstantType::String: os << "String"; break;
            case egli::Statement::ConstantType::Unused: os << "Unused"; break;
        }
    }
    if (!s.parameters.empty()) {
        os << endl;
        for(auto p : s.parameters)
            print(os, p, tab + 2);
        for (size_t i = 0; i < tab; ++i)
            os << " ";
    }
    os << ")" << endl;
}

ostream &operator<<(ostream &os, egli::Statement const &s)
{
    print(os, s);
    return os;
}

ostream &operator<<(ostream &os, egli::VariableTable const &v)
{
    for (auto it : v.find("")) {
        os << it << "(";
        switch (v.typeOf(it)) {
            case egli::Type::Array:
                os << "Array, value=" << egli::detail::builtins::toString_a(v.get<egli::Array>(it));
                break;
            case egli::Type::Boolean:
                os << "Boolean, value=" << egli::detail::builtins::toString_b(v.get<bool>(it));
                break;
            case egli::Type::Edge:
                os << "Edge, value=" << egli::detail::builtins::toString_e(v.get<egli::Edge>(it));
                break;
            case egli::Type::Float:
                os << "Float, value=" << egli::detail::builtins::toString_f(v.get<float>(it));
                break;
            case egli::Type::Graph:
                os << "Graph, value=" << egli::detail::builtins::toString_g(v.get<egli::GraphWrapper>(it));
                break;
            case egli::Type::Integer:
                os << "Integer, value=" << egli::detail::builtins::toString_i(v.get<int>(it));
                break;
            case egli::Type::Number:
                os << "Number, value=" << egli::detail::builtins::toString_n(v.get<egli::Number>(it));
                break;
            case egli::Type::String:
                os << "String, value=" << egli::detail::builtins::toString_s(v.get<string>(it));
                break;
            case egli::Type::Vertex:
                os << "Vertex, value=" << egli::detail::builtins::toString_v(v.get<egli::Vertex>(it));
                break;
        }
        os << ")" << endl;
    }
    return os;
}

IGraph *clone(const IGraph *g) {
    return g->clone();
}

/*! \brief main
 *
 * \return 0
 */
int main()
{
    string in;
    egli::Parser p;
    egli::Statement s;
    egli::detail::Preprocessor pp;
    egli::VariableTable var;
    egli::FunctionTable func;
    egli::detail::interfaceBasics(func);
    egli::detail::interfaceBuiltins(func);
    egli::detail::interfaceAlgorithms(func);

    func.interface("clone", clone);

    while (getline(cin, in)) {
        try {
            pp.stream() << in;
            while (pp.available()) {
                s = p.parse(pp.next());
                cout << "PARSED:\n" << s;
                egli::ProcessingUnit::check(s, func, var);
                egli::ProcessingUnit::process(s, func, var);
                cout << "PROCESSED:\n" << s;
                cout << "TABLE:\n" << var;
            }
            cout << endl;
        } catch (const egli::Exception &e) {
            cout << e.what() << endl;
        }
        cout << endl;
    }

    return 0;
}
