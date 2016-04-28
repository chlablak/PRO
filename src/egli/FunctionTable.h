/*! \brief Function table class
 *
 * \file FunctionTable.h
 * \author Patrick Champion
 * \date 27.04.2016
 */

#ifndef EGLI_DETAIL_FUNCTIONTABLE_H_INCLUDED
#define EGLI_DETAIL_FUNCTIONTABLE_H_INCLUDED

#include <map>
#include <list>
#include <string>

#include "Function.h"
#include "VariableTable.h"
#include "Exception.h"

namespace egli
{
class FunctionTable
{
public:

    // Quick writing
    using name_t = FunctionCaller::name_t;
    using table_t = FunctionCaller::table_t;
    using parameters_t = FunctionCaller::parameters_t;

    /*! \brief Constructor
     */
    FunctionTable();

    // Not copyable (not needed)
    FunctionTable(const FunctionTable&) = delete;
    FunctionTable &operator=(const FunctionTable&) = delete;

    /*! \brief Destructor
     */
    ~FunctionTable();

    /*! \brief Interface a new function
     *
     * \param name - The function name
     * \param func - The function to interface
     *
     * \throw Exception if exists(name) and the return type of the existing
     *        interfaced functions is not the same as func
     */
    template<typename FunctionT>
    void interface(name_t name, FunctionT func);

    /*! \brief Check if a name exists in the table
     *
     * \return true if the name exists
     */
    bool exists(name_t name) const;

    /*! \brief Get the return Type of a function
     *
     * \param name - The function name
     * \return The return Type of the function
     *
     * \throw Exception if !exists(name)
     */
    Type returnType(name_t name) const;

    /*! \brief Check if a function has a match with a list of parameters Type
     *
     * \param name - The function name
     * \param paramsType - The list of parameters Type
     * \return true if there is a match
     */
    bool match(name_t name, const std::vector<Type> &paramsType) const;

    /*! \brief Execute a interfaced function
     *
     * \param name - The function name
     * \param table - The VariableTable used
     * \param dst - The destination variable name for the result
     * \param params - The parameters (found in the table)
     *
     * \throw Exception if !exists(name)
     * \throw Exception if no matching function was found
     */
    void execute(name_t name, table_t table, name_t dst, parameters_t params)
        const;

    /*! \brief Find functions names matching "prefix*"
     *
     * \param prefix - The pattern to match
     * \return A list of matching names
     */
    std::list<std::string> find(name_t prefix) const;

private:

    // Data member
    std::multimap<std::string, FunctionCaller*> functions;
};
} // namespace egli

template<typename FunctionT>
void egli::FunctionTable::interface(name_t name, FunctionT func)
{
    FunctionCaller *caller = makeFunction(func);
    if (exists(name) && returnType(name) != caller->returnType()) {
        delete caller;
        throw Exception("not the same return type",
                        "egli::FunctionTable::interface", name);
    }
    functions.insert(std::make_pair(name, caller));
}

#endif // EGLI_DETAIL_FUNCTIONTABLE_H_INCLUDED
