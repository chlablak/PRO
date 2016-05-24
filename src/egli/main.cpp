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
        os << egli::toString(v.typeOf(it));
        os << ", value=" << v.toString(it);
        os << ")" << endl;
    }
    return os;
}

IGraph *clone(const IGraph *g) {
    return g->clone();
}

vector<int> test(const vector<int> &v) {
    cout << "v (size=" << v.size() << ") -> ";
    for(int i : v)
        cout << i << ' ';
    cout << endl;
    return v;
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
    func.interface("test", test);

    while (getline(cin, in)) {
        pp.stream() << in;
        while (pp.available()) {
            try {
                s = p.parse(pp.next());
                cout << "PARSED:\n" << s;
                egli::ProcessingUnit::check(s, func, var);
                egli::ProcessingUnit::process(s, func, var);
                cout << "PROCESSED:\n" << s;
                cout << "TABLE:\n" << var;
                cout << endl;
            } catch (const runtime_error &e) {
                cout << e.what() << endl;
            }
        }
        cout << endl;
    }

    return 0;
}
