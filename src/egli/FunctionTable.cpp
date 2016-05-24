/*! \brief Function table class
 *
 * \file FunctionTable.cpp
 * \author Patrick Champion
 * \date 27.04.2016
 */

#include "FunctionTable.h"

egli::FunctionTable::FunctionTable() :
    functions()
{}

egli::FunctionTable::~FunctionTable()
{
    for (auto &it : functions)
        delete it.second;
}

bool egli::FunctionTable::exists(name_t name) const
{
    return functions.find(name) != functions.cend();
}

std::list<egli::Type> egli::FunctionTable::returnType(name_t name) const
{
    if (!exists(name))
        throw Exception("unknown name", "egli::FunctionTable::returnType", name);
    std::list<Type> types;
    auto range = functions.equal_range(name);
    for(auto it = range.first; it != range.second; ++it)
        types.push_back(it->second->returnType());
    return types;
}

bool egli::FunctionTable::match(
    name_t name, const std::vector<Type> &paramsType) const
{
    auto range = functions.equal_range(name);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second->arity() != paramsType.size())
            continue;
        bool matching = true;
        for (size_t i = 0; i < it->second->arity(); ++i) {
            if(static_cast<int>(paramsType[i]) == 100) // optional workaround
                continue;                              // see ProcessingUnit
            if (!detail::Matcher::check(it->second->parameterType(i),
                                        paramsType[i])) {
                matching = false;
                break;
            }
        }
        if (matching)
            return true;
    }
    return false;
}

void egli::FunctionTable::execute(
    name_t name, table_t table, name_t dst, parameters_t params) const
{
    if (!exists(name))
        throw Exception("unknown name", "egli::FunctionTable::execute", name);
    auto range = functions.equal_range(name);
    for (auto it = range.first; it != range.second; ++it) {
        if (it->second->match(table, params)) {
            it->second->execute(table, dst, params);
            return;
        }
    }
    throw Exception("no match", "egli::FunctionTable::execute", name);
}

std::list<std::string> egli::FunctionTable::find(name_t prefix) const
{
    std::list<std::string> list;
    for (const auto &it : functions) {
        if (it.first.substr(0, prefix.size()) == prefix)
            list.push_back(it.first);
    }
    return list;
}
