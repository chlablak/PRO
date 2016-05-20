/*! \brief Transform any Type to his String representation
 *
 * \file toString.h
 * \author Patrick Champion
 * \date 20.05.2016
 */

#ifndef EGLI_TOSTRING_H_INCLUDED
#define EGLI_TOSTRING_H_INCLUDED

#include "detail/RealType.h"

namespace egli
{
/*! \brief Transform a RealType to his String representation
 *
 * \param var - The variable to transform
 * \return The String representation
 *
 * \note Declined in many version, one for each Type
 */
detail::RealType<Type::String>::type
    toString(detail::RealType<Type::Array>::cref var);
detail::RealType<Type::String>::type
    toString(detail::RealType<Type::Boolean>::cref var);
detail::RealType<Type::String>::type
    toString(detail::RealType<Type::Edge>::cref var);
detail::RealType<Type::String>::type
    toString(detail::RealType<Type::Float>::cref var);
detail::RealType<Type::String>::type
    toString(detail::RealType<Type::Graph>::cref var);
detail::RealType<Type::String>::type
    toString(detail::RealType<Type::Integer>::cref var);
detail::RealType<Type::String>::type
    toString(detail::RealType<Type::Number>::cref var);
detail::RealType<Type::String>::type
    toString(detail::RealType<Type::String>::cref var);
detail::RealType<Type::String>::type
    toString(detail::RealType<Type::Vertex>::cref var);

/*! \brief Transform a Type to his String representation
 *
 * \param type - The Type to transform
 * \return The String representation
 */
detail::RealType<Type::String>::type toString(Type type);
}

#endif // EGLI_TOSTRING_H_INCLUDED
