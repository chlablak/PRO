/*! \brief Variable table class
 *
 * \file VariableTable.cpp
 * \author Patrick Champion
 * \date 26.04.2016
 */

#include "VariableTable.h"

egli::VariableTable::VariableTable() :
    names(),        // avoid warning -Weffc++
    arrays(),       // ...
    booleans(),
    edges(),
    floats(),
    integers(),
    numbers(),
    strings(),
    vertices(),
    temporaryName()
{}

egli::detail::Type egli::VariableTable::typeOf(const std::string &name) const
{
    return names.find(name)->second;
}

bool egli::VariableTable::exists(const std::string &name) const
{
    return names.find(name) != names.end();
}

void egli::VariableTable::erase(const std::string &name)
{
    if (exists(name)) {
        switch (typeOf(name)) {
            case detail::Type::Array: arrays.erase(name); break;
            case detail::Type::Boolean: booleans.erase(name); break;
            case detail::Type::Edge: edges.erase(name); break;
            case detail::Type::Float: floats.erase(name); break;
            //case detail::Type::Graph: graphs.erase(name); break;
            case detail::Type::Integer: integers.erase(name); break;
            case detail::Type::Number: numbers.erase(name); break;
            case detail::Type::String: strings.erase(name); break;
            case detail::Type::Vertex: vertices.erase(name); break;
        }
        names.erase(name);
    }
}

void egli::VariableTable::clear()
{
    names.clear();
    arrays.clear();
    booleans.clear();
    edges.clear();
    floats.clear();
    integers.clear();
    numbers.clear();
    strings.clear();
    vertices.clear();
    temporaryName.reset();
}

void egli::VariableTable::enter()
{
    temporaryName.enter();
}

void egli::VariableTable::leave()
{
    #warning besoin du TST + modif. erase()
    for (const std::string &it : find(temporaryName.prefix()))
        erase(it);
    temporaryName.leave();
}

std::list<std::string>
    egli::VariableTable::find(const std::string &prefix) const
{
    std::list<std::string> list;
    for (const auto &it : names) {
        if (it.first.substr(0, prefix.size()) == prefix)
            list.push_back(it.first);
    }
    return list;
}
