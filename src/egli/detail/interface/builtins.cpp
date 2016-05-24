/*! \brief Built-ins functions to interface
 *
 * \file builtins.cpp
 * \author Patrick Champion
 * \date 03.05.2016
 */

#include <sstream>
#include <string>
#include <fstream>

#include "builtins.h"
#include "../../Array.h"
#include "../../TEdge.h"
#include "../../Number.h"
#include "../../TVertex.h"
#include "../../GraphWrapper.h"
#include "../../Exception.h"
#include "../../Data.h"
#include "../../Interpreter.h"
#include "../../Statement.h"

egli::detail::RealType<egli::Type::Boolean>::type
    egli::detail::builtins::save(RealType<Type::Graph>::cref g,
                                 RealType<Type::String>::cref file)
{
    std::ofstream ofs(file.c_str(), std::ios::out | std::ios::trunc);
    if (!ofs)
        throw Exception("can't open file", "egli::builtins::save", file);
    ofs << toString_g(g);
    return true;
}

egli::detail::RealType<egli::Type::Graph>::type
    egli::detail::builtins::load(RealType<Type::String>::cref file)
{
    std::ifstream ifs(file.c_str(), std::ios::in);
    if (!ifs)
        throw Exception("can't open file", "egli::builtins::load", file);
    Data data;
    Interpreter interpreter(&data);
    interpreter.writer() << "g=" << ifs.rdbuf() << ';';
    Statement statement = interpreter.next();
    return data.variables().get<RealType<Type::Graph>::type>(statement.value);
}

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
        if (!it->label().empty() && it->label() != toString_i(it->id()))
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
    }
    GraphWrapper::GraphType type = var.graphType();
    bool showWeight = var.graph()->isWeighted();
    for (const auto *it : var.graph()->edgeList()) {
        oss << ',';
        oss << it->from()->id();
        oss << (type == GraphWrapper::GraphType::Graph ? "--" : "->");
        oss << it->to()->id();
        size_t countEmpty = 0;
        if (showWeight)
            oss << ':' << it->weight();
        else
            ++countEmpty;
        if (!it->label().empty()) {
            for (size_t i = 0; i < countEmpty + 1; ++i)
                oss << ':';
            oss << '"' << it->label() << '"';
            countEmpty = 0;
        }
        else
            ++countEmpty;
        if (type == GraphWrapper::GraphType::FlowGraph) {
            const FlowEdge *fe = dynamic_cast<const FlowEdge*>(it);
            if (fe->maxCapacity() != -1) {
                for (size_t i = 0; i < countEmpty + 1; ++i)
                    oss << ':';
                oss << fe->maxCapacity();
                countEmpty = 0;
            }
            else
                ++countEmpty;
            if (fe->minCapacity() != -1) {
                for (size_t i = 0; i < countEmpty + 1; ++i)
                    oss << ':';
                oss << fe->minCapacity();
                countEmpty = 0;
            }
        }
    }
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

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::typeOf_a(RealType<Type::Array>::cref)
{
    return "Array";
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::typeOf_b(RealType<Type::Boolean>::cref)
{
    return "Boolean";
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::typeOf_e(RealType<Type::Edge>::cref)
{
    return "Edge";
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::typeOf_f(RealType<Type::Float>::cref)
{
    return "Float";
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::typeOf_g(RealType<Type::Graph>::cref var)
{
    switch (var.graphType()) {
        case GraphWrapper::GraphType::Graph: return "Graph";
        case GraphWrapper::GraphType::DiGraph: return "DiGraph";
        case GraphWrapper::GraphType::FlowGraph: return "FlowGraph";
    }
    return ""; // impossible case
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::typeOf_i(RealType<Type::Integer>::cref)
{
    return "Integer";
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::typeOf_n(RealType<Type::Number>::cref)
{
    return "Number";
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::typeOf_s(RealType<Type::String>::cref)
{
    return "String";
}

egli::detail::RealType<egli::Type::String>::type
    egli::detail::builtins::typeOf_v(RealType<Type::Vertex>::cref)
{
    return "Vertex";
}
