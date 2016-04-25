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
#include "../utility/Optional.h"

using namespace std;

void print(ostream &os, egli::detail::Statement const &s, size_t tab = 0)
{
    for (size_t i = 0; i < tab; ++i)
        os << " ";
    switch (s.type) {
        case egli::detail::Statement::Type::Assignation: os << "Assignation"; break;
        case egli::detail::Statement::Type::Array: os << "Array"; break;
        case egli::detail::Statement::Type::Constant: os << "Constant"; break;
        case egli::detail::Statement::Type::Function: os << "Function"; break;
        case egli::detail::Statement::Type::None: os << "None"; break;
        case egli::detail::Statement::Type::Variable: os << "Variable"; break;
    }
    os << "(\"" << s.value << "\"";
    if (s.type == egli::detail::Statement::Type::Constant) {
        os << " ";
        switch (s.constantType) {
            case egli::detail::Statement::ConstantType::Boolean: os << "Boolean"; break;
            case egli::detail::Statement::ConstantType::Float: os << "Float"; break;
            case egli::detail::Statement::ConstantType::Integer: os << "Integer"; break;
            case egli::detail::Statement::ConstantType::String: os << "String"; break;
            case egli::detail::Statement::ConstantType::Unused: os << "Unused"; break;
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

ostream &operator<<(ostream &os, egli::detail::Statement const &s)
{
    print(os, s);
    return os;
}

/*! \brief main
 *
 * \return 0
 */
int main()
{
    string in;
    egli::Parser p;
    egli::detail::Statement s;
    while (getline(cin, in) && !in.empty()) {
        try {
            s = p.parse(in);
            cout << s << endl;
        } catch (const egli::Exception &e) {
            cout << e.what() << endl;
        }
        cout << endl;
    }

    return 0;
}
