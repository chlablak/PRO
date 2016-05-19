/*! \brief Built-ins functions to interface
 *
 * \file builtins.cpp
 * \author Patrick Champion
 * \date 03.05.2016
 */

#include <sstream>
#include <string>

#include "builtins.h"
#include "../../Array.h"
#include "../../Edge.h"
#include "../../Number.h"
#include "../../Vertex.h"
#include "../../GraphWrapper.h"

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::toString_a(RealType<Type::Array>::cref var)
{
    std::ostringstream oss;
    oss << '[';
    for (size_t i = 0; i < var.size(); ++i) {
        if (i > 0)
            oss << ',';
        switch (var.typeOf(i)) {
            case Type::Array:
                oss << toString_a(var.get<RealType<Type::Array>::type>(i));
                break;
            case Type::Boolean:
                oss << toString_b(var.get<RealType<Type::Boolean>::type>(i));
                break;
            case Type::Edge:
                oss << toString_e(var.get<RealType<Type::Edge>::type>(i));
                break;
            case Type::Float:
                oss << toString_f(var.get<RealType<Type::Float>::type>(i));
                break;
            case Type::Graph:
                oss << toString_g(var.get<RealType<Type::Graph>::type>(i));
                break;
            case Type::Integer:
                oss << toString_i(var.get<RealType<Type::Integer>::type>(i));
                break;
            case Type::Number:
                oss << toString_n(var.get<RealType<Type::Number>::type>(i));
                break;
            case Type::String:
                oss << toString_s(var.get<RealType<Type::String>::type>(i));
                break;
            case Type::Vertex:
                oss << toString_v(var.get<RealType<Type::Vertex>::type>(i));
                break;
        }
    }
    oss << ']';
    return oss.str();
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::toString_b(RealType<Type::Boolean>::cref var)
{
    return var ? "True" : "False";
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::toString_e(RealType<Type::Edge>::cref var)
{
    int countEmpty = 0;
    std::ostringstream oss;
    oss << '(' << var.v;
    oss << (var.connection == Edge::Connection::Bidirectional ? "--" : "->");
    oss << var.w;
    if (var.id.hasValue())
        oss << '[' << var.id.value() << ']';
    if (var.weight.hasValue())
        oss << ':' << toString_n(var.weight.value());
    else
        ++countEmpty;
    if (var.label.hasValue()) {
        for (int i = 0; i < countEmpty + 1; ++i)
            oss << ':';
        oss << toString_s(var.label.value());
        countEmpty = 0;
    }
    else
        ++countEmpty;
    if (var.maxCapacity.hasValue()) {
        for (int i = 0; i < countEmpty + 1; ++i)
            oss << ':';
        oss << toString_n(var.maxCapacity.value());
        countEmpty = 0;
    }
    else
        ++countEmpty;
    if (var.minCapacity.hasValue()) {
        for (int i = 0; i < countEmpty + 1; ++i)
            oss << ':';
        oss << toString_n(var.minCapacity.value());
    }
    oss << ')';
    return oss.str();
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::toString_f(RealType<Type::Float>::cref var)
{
    std::ostringstream oss;
    oss << var;
    return oss.str();
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::toString_g(RealType<Type::Graph>::cref var)
{
    std::ostringstream oss;
    oss << '{';
    bool first = true;
    for (const auto *it : var.graph()->vertexList()) {
        if (first)
            first = false;
        else
            oss << ',';
        oss << it->id();
        size_t countEmpty = 0;
        if (!it->label().empty())
            oss << ':' << '"' << it->label() << '"';
        else
            ++countEmpty;
        if (it->weight() < std::numeric_limits<double>::max()) {
            for (size_t i = 0; i < countEmpty + 1; ++i)
                oss << ':';
            oss << it->weight();
            countEmpty = 0;
        }
        else
            ++countEmpty;
        if (it->maxCapacity() != -1) {
            for (size_t i = 0; i < countEmpty + 1; ++i)
                oss << ':';
            oss << it->maxCapacity();
            countEmpty = 0;
        }
        else
            ++countEmpty;
        if (it->minCapacity() != -1) {
            for (size_t i = 0; i < countEmpty + 1; ++i)
                oss << ':';
            oss << it->minCapacity();
            countEmpty = 0;
        }
        else
            ++countEmpty;
    }
    #warning TODO toString_g Edge
    oss << '}';
    return oss.str();
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::toString_i(RealType<Type::Integer>::cref var)
{
    std::ostringstream oss;
    oss << var;
    return oss.str();
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::toString_n(RealType<Type::Number>::cref var)
{
    return var.isInteger() ? toString_i(var) : toString_f(var);
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::toString_s(RealType<Type::String>::cref var)
{
    RealType<Type::String>::type tmp = "\"";
    return tmp + var + "\"";
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::toString_v(RealType<Type::Vertex>::cref var)
{
    int countEmpty = 0;
    std::ostringstream oss;
    oss << '(' << var.id;
    if (var.label.hasValue())
        oss << ':' << toString_s(var.label.value());
    else
        ++countEmpty;
    if (var.weight.hasValue()) {
        for (int i = 0; i < countEmpty + 1; ++i)
            oss << ':';
        oss << toString_n(var.weight.value());
        countEmpty = 0;
    }
    else
        ++countEmpty;
    if (var.maxCapacity.hasValue()) {
        for (int i = 0; i < countEmpty + 1; ++i)
            oss << ':';
        oss << toString_n(var.maxCapacity.value());
        countEmpty = 0;
    }
    else
        ++countEmpty;
    if (var.minCapacity.hasValue()) {
        for (int i = 0; i < countEmpty + 1; ++i)
            oss << ':';
        oss << toString_n(var.minCapacity.value());
    }
    oss << ')';
    return oss.str();
}
