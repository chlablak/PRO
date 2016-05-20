/*! \brief Transform a Type to his String representation
 *
 * \file toString.cpp
 * \author Patrick Champion
 * \date 20.05.2016
 */

#include "toString.h"
#include "detail/interface/builtins.h"


egli::detail::RealType<egli::Type::String>::type
    egli::toString(detail::RealType<Type::Array>::cref var)
{
    return detail::builtins::toString_a(var);
}

egli::detail::RealType<egli::Type::String>::type
    egli::toString(detail::RealType<Type::Boolean>::cref var)
{
    return detail::builtins::toString_b(var);
}

egli::detail::RealType<egli::Type::String>::type
    egli::toString(detail::RealType<Type::Edge>::cref var)
{
    return detail::builtins::toString_e(var);
}

egli::detail::RealType<egli::Type::String>::type
    egli::toString(detail::RealType<Type::Float>::cref var)
{
    return detail::builtins::toString_f(var);
}

egli::detail::RealType<egli::Type::String>::type
    egli::toString(detail::RealType<Type::Graph>::cref var)
{
    return detail::builtins::toString_g(var);
}

egli::detail::RealType<egli::Type::String>::type
    egli::toString(detail::RealType<Type::Integer>::cref var)
{
    return detail::builtins::toString_i(var);
}

egli::detail::RealType<egli::Type::String>::type
    egli::toString(detail::RealType<Type::Number>::cref var)
{
    return detail::builtins::toString_n(var);
}

egli::detail::RealType<egli::Type::String>::type
    egli::toString(detail::RealType<Type::String>::cref var)
{
    return detail::builtins::toString_s(var);
}

egli::detail::RealType<egli::Type::String>::type
    egli::toString(detail::RealType<Type::Vertex>::cref var)
{
    return detail::builtins::toString_v(var);
}

egli::detail::RealType<egli::Type::String>::type egli::toString(Type type)
{
    switch (type) {
        case Type::Array: return "Array";
        case Type::Boolean: return "Boolean";
        case Type::Edge: return "Edge";
        case Type::Float: return "Float";
        case Type::Graph: return "Graph";
        case Type::Integer: return "Integer";
        case Type::Number: return "Number";
        case Type::String: return "String";
        case Type::Vertex: return "Vertex";
    }
}
