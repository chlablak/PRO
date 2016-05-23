/*! \brief Statement processing unit class
 *
 * \file ProcessingUnit.cpp
 * \author Patrick Champion
 * \date 02.05.2016
 */

#include <vector>
#include <cstdlib>

#include "ProcessingUnit.h"
#include "Exception.h"
#include "detail/RealType.h"

// std::stoi, std::stof and std::stoul not defined in MinGW
namespace egli
{
namespace detail
{
int stoi(const std::string &str)
{
    return std::strtol(str.c_str(), nullptr, 10);
}
float stof(const std::string &str)
{
    return strtof(str.c_str(), nullptr);
}
unsigned long stoul(const std::string &str)
{
    return std::strtoul(str.c_str(), nullptr, 10);
}
} // namespace detail
} // namespace egli

void egli::ProcessingUnit::check(const Statement &statement,
                                 const FunctionTable &functions,
                                 const VariableTable &variables)
{
    // first check sub-statements
    for (const Statement &substatement : statement.parameters)
        check(substatement, functions, variables);

    // then check the root statement
    switch (statement.type) {
        case Statement::Type::None:
            // nothing to do
            break;

        case Statement::Type::Assignation:
            if (functions.exists(statement.value))
                throw Exception("function is not assignable",
                                "egli::ProcessingUnit::check",
                                statement.value);
            break;

        case Statement::Type::Array:
            if (!statement.value.empty() && !variables.exists(statement.value))
                throw Exception("identifier not found",
                                "egli::ProcessingUnit::check",
                                statement.value);
            if (!statement.value.empty()
                && detail::stoul(statement.parameters.at(0).value) >=
                    variables.get<detail::RealType<Type::Array>::type>(
                        statement.value).size())
                throw Exception("indexed array out of range",
                                "egli::ProcessingUnit::check",
                                statement.value);
            break;

        case Statement::Type::Constant:
            // nothing to do
            break;

        case Statement::Type::Function:
            checkFunction(statement, functions, variables);
            break;

        case Statement::Type::Variable:
            if (!variables.exists(statement.value))
                throw Exception("identifier not found",
                                "egli::ProcessingUnit::check",
                                statement.value);
            break;
    }
}

void egli::ProcessingUnit::process(Statement &statement,
                                   const FunctionTable &functions,
                                   VariableTable &variables)
{
    // Enter a new temporary level
    //TemporaryScope scope(variables);
    #warning level are not used

    // Process the statement
    processStatement(statement, functions, variables);
}

void egli::ProcessingUnit::checkFunction(const Statement &statement,
                                         const FunctionTable &functions,
                                         const VariableTable &variables)
{
    // first check for the function existance
    if (!functions.exists(statement.value))
        throw Exception("function not found",
                        "egli::ProcessingUnit::checkFunction",
                        statement.value);

    // construct the parameters type list
    std::vector<Type> paramsType;
    for (const Statement &param : statement.parameters) {
        switch (param.type) {
            case Statement::Type::None:
                paramsType.push_back(static_cast<Type>(100)); // optional workaround
                break;

            case Statement::Type::Assignation:
                // impossible case
                break;

            case Statement::Type::Array:
                if (param.value.empty())
                    paramsType.push_back(Type::Array);
                else // indexed-array
                    paramsType.push_back(
                        variables.get<detail::RealType<Type::Array>::type>(
                            param.value).typeOf(detail::stoul(param.parameters.at(0).value)));
                break;

            case Statement::Type::Constant:
                switch (param.constantType) {
                    case Statement::ConstantType::Unused:
                        // impossible case
                        break;

                    case Statement::ConstantType::Boolean:
                        paramsType.push_back(Type::Boolean);
                        break;

                    case Statement::ConstantType::Float:
                        paramsType.push_back(Type::Float);
                        break;

                    case Statement::ConstantType::Integer:
                        paramsType.push_back(Type::Integer);
                        break;

                    case Statement::ConstantType::String:
                        paramsType.push_back(Type::String);
                        break;
                }
                break;

            case Statement::Type::Function: {
                std::list<Type> types = functions.returnType(param.value);
                if(types.size() == 1)
                    paramsType.push_back(types.front());
                else
                    paramsType.push_back(static_cast<Type>(100));
                break;
            }

            case Statement::Type::Variable:
                paramsType.push_back(variables.typeOf(param.value));
                break;
        }
    }

    // check if there is a matching function
    if (!functions.match(statement.value, paramsType))
        throw Exception("parameters do not match",
                        "egli::ProcessingUnit::checkFunction",
                        statement.value);
}

void egli::ProcessingUnit::processStatement(Statement &statement,
                                            const FunctionTable &functions,
                                            VariableTable &variables)
{
    // first process sub-statements
    for(Statement &substatement : statement.parameters)
        processStatement(substatement, functions, variables);

    // then process the root statement
    switch (statement.type) {
        case Statement::Type::None:
            // nothing to do
            break;

        case Statement::Type::Assignation:
            processAssignation(statement, variables);
            break;

        case Statement::Type::Array:
            processArray(statement, variables);
            break;

        case Statement::Type::Constant:
            processConstant(statement, variables);
            break;

        case Statement::Type::Function:
            processFunction(statement, functions, variables);
            break;

        case Statement::Type::Variable:
            // nothing to do
            break;
    }
}

void egli::ProcessingUnit::processAssignation(Statement &statement,
                                              VariableTable &variables)
{
    if (variables.isTemporary(statement.parameters.at(0).value))
        variables.move(statement.value, statement.parameters.at(0).value);
    else
        variables.copy(statement.value, statement.parameters.at(0).value);

    statement.transformToVariable(statement.value);
}

void egli::ProcessingUnit::processArray(Statement &statement,
                                        VariableTable &variables)
{
    if (statement.value.empty()) { // create array
        detail::RealType<Type::Array>::type tmp;
        for (const Statement &param : statement.parameters) {
            switch (variables.typeOf(param.value)) {
                case Type::Array:
                    tmp.add(variables.get<detail::RealType<Type::Array>::type>(
                        param.value));
                    break;
                case Type::Boolean:
                    tmp.add(variables.get<detail::RealType<Type::Boolean>::type>(
                        param.value));
                    break;
                case Type::Edge:
                    tmp.add(variables.get<detail::RealType<Type::Edge>::type>(
                        param.value));
                    break;
                case Type::Float:
                    tmp.add(variables.get<detail::RealType<Type::Float>::type>(
                        param.value));
                    break;
                case Type::Graph:
                    tmp.add(variables.get<detail::RealType<Type::Graph>::type>(
                        param.value));
                    break;
                case Type::Number:
                    tmp.add(variables.get<detail::RealType<Type::Number>::type>(
                        param.value));
                    break;
                case Type::Integer:
                    tmp.add(variables.get<detail::RealType<Type::Integer>::type>(
                        param.value));
                    break;
                case Type::String:
                    tmp.add(variables.get<detail::RealType<Type::String>::type>(
                        param.value));
                    break;
                case Type::Vertex:
                    tmp.add(variables.get<detail::RealType<Type::Vertex>::type>(
                        param.value));
                    break;
            }
        }
        statement.transformToVariable(variables.setTemporary(tmp));

    } else { // indexed array
        size_t index = variables.get<detail::RealType<Type::Integer>::type>(
            statement.parameters.at(0).value);
        detail::RealType<Type::Array>::cref tmp =
            variables.get<detail::RealType<Type::Array>::type>(statement.value);
        switch (tmp.typeOf(index)) {
            case Type::Array:
                statement.transformToVariable(variables.setTemporary(
                    tmp.get<detail::RealType<Type::Array>::type>(index)));
                break;
            case Type::Boolean:
                statement.transformToVariable(variables.setTemporary(
                    tmp.get<detail::RealType<Type::Boolean>::type>(index)));
                break;
            case Type::Edge:
                statement.transformToVariable(variables.setTemporary(
                    tmp.get<detail::RealType<Type::Edge>::type>(index)));
                break;
            case Type::Float:
                statement.transformToVariable(variables.setTemporary(
                    tmp.get<detail::RealType<Type::Float>::type>(index)));
                break;
            case Type::Graph:
                statement.transformToVariable(variables.setTemporary(
                    tmp.get<detail::RealType<Type::Graph>::type>(index)));
                break;
            case Type::Number:
                statement.transformToVariable(variables.setTemporary(
                    tmp.get<detail::RealType<Type::Number>::type>(index)));
                break;
            case Type::Integer:
                statement.transformToVariable(variables.setTemporary(
                    tmp.get<detail::RealType<Type::Integer>::type>(index)));
                break;
            case Type::String:
                statement.transformToVariable(variables.setTemporary(
                    tmp.get<detail::RealType<Type::String>::type>(index)));
                break;
            case Type::Vertex:
                statement.transformToVariable(variables.setTemporary(
                    tmp.get<detail::RealType<Type::Vertex>::type>(index)));
                break;
        }
    }
}

void egli::ProcessingUnit::processConstant(Statement &statement,
                                           VariableTable &variables)
{
    switch (statement.constantType) {
        case Statement::ConstantType::Unused:
            // impossible case
            break;

        case Statement::ConstantType::Boolean:
            statement.transformToVariable(
                variables.setTemporary(statement.value == "True"));
            break;

        case Statement::ConstantType::Float:
            statement.transformToVariable(
                variables.setTemporary(detail::stof(statement.value)));
            break;

        case Statement::ConstantType::Integer:
            statement.transformToVariable(
                variables.setTemporary(detail::stoi(statement.value)));
            break;

        case Statement::ConstantType::String:
            statement.transformToVariable(
                variables.setTemporary(statement.value));
            break;
    }
}

void egli::ProcessingUnit::processFunction(Statement &statement,
                                           const FunctionTable &functions,
                                           VariableTable &variables)
{
    std::string dst = variables.nextTemporaryName();
    std::vector<std::string> params;
    for(const Statement &param : statement.parameters)
        params.push_back(param.value);
    functions.execute(statement.value, variables, dst, params);
    statement.transformToVariable(dst);
}
