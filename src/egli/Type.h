/*! \brief Define the types used
 *
 * \file Type.h
 * \author Patrick Champion
 * \date 25.04.2016
 */

#ifndef EGLI_TYPE_H_INCLUDED
#define EGLI_TYPE_H_INCLUDED

namespace egli
{
/*! \brief ID typedef
 */
using id_type = unsigned int;

/*! \brief Types enumeration
 */
enum class Type
{
    Array,
    Boolean,
    Edge,
    Float,
    Graph,
    Integer,
    Number,
    String,
    Vertex
};
} // namespace egli

#endif // EGLI_TYPE_H_INCLUDED
