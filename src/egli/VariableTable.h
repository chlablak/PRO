/*! \brief Variable table class
 *
 * \file VariableTable.h
 * \author Patrick Champion
 * \date 26.04.2016
 */

#ifndef EGLI_VARIABLETABLE_H_INCLUDED
#define EGLI_VARIABLETABLE_H_INCLUDED

#include <map>
#include <list>
#include <string>

#warning replace std::map with utility::TstMap
#warning getTemporaryName() (ou dans FunctionTable...)

#include "Exception.h"
#include "Array.h"
#include "Edge.h"
#include "Number.h"
#include "Vertex.h"
#include "Type.h"
#include "detail/EnumValue.h"
#include "detail/RealType.h"
#include "detail/TemporaryName.h"

// Quick writing
#define EGLI_VARIABLETABLE_DEF_TABLEHELPER(T, V) \
    template<typename Dummy> \
    struct TableHelperImpl<T, Dummy> \
    { \
        static void \
            set(VariableTable &table, name_t name, const T &value) \
        { \
            table.V[name] = value; \
        } \
        static const T & \
            get(const VariableTable &table, name_t name) \
        { \
            return table.V.find(name)->second; \
        } \
    };

namespace egli
{
/*! \brief Variable table
 */
class VariableTable
{
public:

    // Quick writing
    using name_t = const std::string&;

    /*! \brief Constructor
     */
    VariableTable();

    /*! \brief Gave a variable a value
     *
     * \param name - The variable name
     * \param value - The variable value
     */
    template<typename T>
    void set(name_t name, const T &value);

    /*! \brief Get a temporary variable with a specific value
     *
     * \param value - The variable value
     * \return The variable name
     */
    template<typename T>
    std::string setTemporary(const T &value);

    /*! \brief Get the Type of a variable
     *
     * \param name - The variable name
     * \return The Type of the variable
     *
     * \throw Exception if !exists(name)
     */
    Type typeOf(name_t name) const;

    /*! \brief Check if a variable exists
     *
     * \param name - The variable name
     * \return true if the variable exists
     */
    bool exists(name_t name) const;

    /*! \brief Remove a variable
     *
     * \param name - The variable name
     */
    void erase(name_t name);

    /*! \brief Get a variable value
     *
     * \param name - The variable name
     * \return The variable value
     *
     * \throw Exception if !exists(name) or if typeOf(name) != T
     */
    template<typename T>
    const T &get(name_t name) const;

    /*! \brief Clear all variables
     */
    void clear();

    /*! \brief Enter a new level of temporary variables
     */
    void enter();

    /*! \brief Leave the current level of temporary variables
     */
    void leave();

    /*! \brief Find variables names matching "prefix*"
     *
     * \param prefix - The pattern to match
     * \return A list of matching names
     */
    std::list<std::string> find(name_t prefix) const;

    /*! \brief Move a variable to a new/other one
     *
     * \param dst - The destination variable
     * \param src - The source variable
     *
     * \throw Exception if !exists(src)
     * \post exists(src) == false
     */
    void move(name_t dst, name_t src);

    /*! \brief Copy a variable to a new/other one
     *
     * \param dst - The destination variable
     * \param src - The source variable
     *
     * \throw Exception if !exists(src)
     */
    void copy(name_t dst, name_t src);

    /*! \brief Check if a variable is temporary or not
     *
     * \param name - The variable name
     * \return true if the variable is temporary
     *
     * \throw Exception if !exists(name)
     */
    bool isTemporary(name_t name) const;

    /*! \brief Get the next temporary name
     *
     * \return The name
     */
    std::string nextTemporaryName();

private:

    // Easy writing
    using array_t = detail::RealType<Type::Array>::type;
    using boolean_t = detail::RealType<Type::Boolean>::type;
    using edge_t = detail::RealType<Type::Edge>::type;
    using float_t = detail::RealType<Type::Float>::type;
    //using graph_t = detail::RealType<Type::Graph>::type;
    using integer_t = detail::RealType<Type::Integer>::type;
    using number_t = detail::RealType<Type::Number>::type;
    using string_t = detail::RealType<Type::String>::type;
    using vertex_t = detail::RealType<Type::Vertex>::type;

    // Store the Type behind a name
    std::map<std::string, Type> names;

    // Storage for values
    std::map<std::string, array_t> arrays;
    std::map<std::string, boolean_t> booleans;
    std::map<std::string, edge_t> edges;
    std::map<std::string, float_t> floats;
    //std::map<std::string, graph_t> graphs;
    std::map<std::string, integer_t> integers;
    std::map<std::string, number_t> numbers;
    std::map<std::string, string_t> strings;
    std::map<std::string, vertex_t> vertices;

    // Generate temporary names
    detail::TemporaryName temporaryName;

    // Simplify operations on storage maps (impl)
    template<typename T, typename Dummy = void>
    struct TableHelperImpl;

    // Simplify operations on storage maps
    template<typename T>
    using TableHelper = TableHelperImpl<T>;

    // Specializations for the table helper
    EGLI_VARIABLETABLE_DEF_TABLEHELPER(array_t, arrays)
    EGLI_VARIABLETABLE_DEF_TABLEHELPER(boolean_t, booleans)
    EGLI_VARIABLETABLE_DEF_TABLEHELPER(edge_t, edges)
    EGLI_VARIABLETABLE_DEF_TABLEHELPER(float_t, floats)
    //EGLI_VARIABLETABLE_DEF_TABLEHELPER(graph_t, graphs)
    EGLI_VARIABLETABLE_DEF_TABLEHELPER(integer_t, integers)
    EGLI_VARIABLETABLE_DEF_TABLEHELPER(number_t, numbers)
    EGLI_VARIABLETABLE_DEF_TABLEHELPER(string_t, strings)
    EGLI_VARIABLETABLE_DEF_TABLEHELPER(vertex_t, vertices)
};

/*! \brief RAII-style class for enter()/leave() in the VariableTable
 */
class TemporaryScope
{
public:

    /*! \brief Constructor
     *
     * \param table - The VariableTable
     *
     * \note Calls table.enter()
     */
    TemporaryScope(VariableTable &table);

    // Not needed, avoid pointer problem
    TemporaryScope(const TemporaryScope&) = delete;
    TemporaryScope &operator=(const TemporaryScope&) = delete;

    /*! \brief Destructor
     *
     * \note Calls table.leave()
     */
    ~TemporaryScope();

private:

    // data member
    VariableTable *table;
};
} // namespace egli

template<typename T>
void egli::VariableTable::set(name_t name, const T &value)
{
    if (exists(name) && typeOf(name) != detail::EnumValue<T>::value)
        erase(name);
    else
        names[name] = detail::EnumValue<T>::value;

    TableHelper<T>::set(*this, name, value);
}

template<typename T>
std::string egli::VariableTable::setTemporary(const T &value)
{
    std::string name = temporaryName.next();
    set(name, value);
    return name;
}

template<typename T>
const T &egli::VariableTable::get(name_t name) const
{
    if (!exists(name))
        throw Exception("invalid name", "egli::VariableTable::get");
    if (typeOf(name) != detail::EnumValue<T>::value)
        throw Exception("bad type cast", "egli::VariableTable::get");

    return TableHelper<T>::get(*this, name);
}

// No need anymore
#undef EGLI_VARIABLETABLE_DEF_TABLEHELPER

#endif // EGLI_VARIABLETABLE_H_INCLUDED
