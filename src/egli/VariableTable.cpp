/*! \brief Variable table class
 *
 * \file VariableTable.cpp
 * \author Patrick Champion
 * \date 26.04.2016
 */

#include "VariableTable.h"
#include "toString.h"

egli::VariableTable::VariableTable() :
    names(),        // avoid warning -Weffc++
    arrays(),       // ...
    booleans(),
    edges(),
    floats(),
    graphs(),
    integers(),
    numbers(),
    strings(),
    vertices(),
    temporaryName()
{}

egli::Type egli::VariableTable::typeOf(name_t name) const
{
    if (!exists(name))
        throw Exception("unknown name", "egli::VariableTable::typeOf", name);
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
            case Type::Graph: graphs.erase(name); break;
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
    graphs.clear();
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
    for (const std::string &it : find(temporaryName.prefix()))
        erase(it);
    temporaryName.leave();
}

std::list<std::string>
    egli::VariableTable::find(name_t prefix) const
{
    std::list<std::string> list;
    for (const auto &it : names) {
        if (it.first.substr(0, prefix.size()) == prefix)
            list.push_back(it.first);
    }
    return list;
}

void egli::VariableTable::move(name_t dst, name_t src)
{
    copy(dst, src);
    erase(src);
}

void egli::VariableTable::copy(name_t dst, name_t src)
{
    if (!exists(src))
        throw Exception("source unavailable", "egli::VariableTable::copy", src);
    if (exists(dst))
        erase(dst);
    switch(typeOf(src)) {
        case Type::Array:
            set(dst, get<detail::RealType<Type::Array>::type>(src));
            break;
        case Type::Boolean:
            set(dst, get<detail::RealType<Type::Boolean>::type>(src));
            break;
        case Type::Edge:
            set(dst, get<detail::RealType<Type::Edge>::type>(src));
            break;
        case Type::Float:
            set(dst, get<detail::RealType<Type::Float>::type>(src));
            break;
        case Type::Graph:
            set(dst, get<detail::RealType<Type::Graph>::type>(src));
            break;
        case Type::Integer:
            set(dst, get<detail::RealType<Type::Integer>::type>(src));
            break;
        case Type::Number:
            set(dst, get<detail::RealType<Type::Number>::type>(src));
            break;
        case Type::String:
            set(dst, get<detail::RealType<Type::String>::type>(src));
            break;
        case Type::Vertex:
            set(dst, get<detail::RealType<Type::Vertex>::type>(src));
            break;
    }
}

bool egli::VariableTable::isTemporary(name_t name) const
{
    if (!exists(name))
        throw Exception("unknown name", "egli::VariableTable::isTemporary", name);
    return !name.empty() && name[0] == '_';
}

std::string egli::VariableTable::nextTemporaryName()
{
    return temporaryName.next();
}

egli::detail::RealType<egli::Type::String>::type
    egli::VariableTable::toString(name_t name) const
{
    if (!exists(name))
        throw Exception("unknown name", "egli::VariableTable::toString", name);

    switch (typeOf(name)) {
        case Type::Array:
            return egli::toString(get<detail::RealType<Type::Array>::type>(name));
        case Type::Boolean:
            return egli::toString(get<detail::RealType<Type::Boolean>::type>(name));
        case Type::Edge:
            return egli::toString(get<detail::RealType<Type::Edge>::type>(name));
        case Type::Float:
            return egli::toString(get<detail::RealType<Type::Float>::type>(name));
        case Type::Graph:
            return egli::toString(get<detail::RealType<Type::Graph>::type>(name));
        case Type::Integer:
            return egli::toString(get<detail::RealType<Type::Integer>::type>(name));
        case Type::Number:
            return egli::toString(get<detail::RealType<Type::Number>::type>(name));
        case Type::String:
            return egli::toString(get<detail::RealType<Type::String>::type>(name));
        case Type::Vertex:
            return egli::toString(get<detail::RealType<Type::Vertex>::type>(name));
    }
}

egli::TemporaryScope::TemporaryScope(VariableTable &table_) :
    table(&table_)
{
    table->enter();
}

egli::TemporaryScope::~TemporaryScope()
{
    table->leave();
}
