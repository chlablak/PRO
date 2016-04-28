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

egli::Type egli::VariableTable::typeOf(name_t name) const
{
    return names.find(name)->second;
}

bool egli::VariableTable::exists(name_t name) const
{
    return names.find(name) != names.end();
}

void egli::VariableTable::erase(name_t name)
{
    if (exists(name)) {
        switch (typeOf(name)) {
            case Type::Array: arrays.erase(name); break;
            case Type::Boolean: booleans.erase(name); break;
            case Type::Edge: edges.erase(name); break;
            case Type::Float: floats.erase(name); break;
            //case Type::Graph: graphs.erase(name); break;
            case Type::Integer: integers.erase(name); break;
            case Type::Number: numbers.erase(name); break;
            case Type::String: strings.erase(name); break;
            case Type::Vertex: vertices.erase(name); break;
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
