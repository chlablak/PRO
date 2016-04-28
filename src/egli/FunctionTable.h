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
#include <forward_list>
#include <string>

#include "Function.h"
#include "VariableTable.h"

#warning header + cpp pas fini

namespace egli
{
class FunctionTable
{
public:

    using name_t = FunctionCaller::name_t;
    using table_t = FunctionCaller::table_t;
    using parameters_t = FunctionCaller::parameters_t;

    FunctionTable();

    ~FunctionTable();

    template<typename FunctionT>
    void interface(name_t name, FunctionT func);

    bool exists(name_t name) const;

    Type returnType(name_t name) const;

    bool match(name_t name, table_t table, parameters_t params) const;

    void execute(name_t name, table_t table, name_t dst, parameters_t params)
        const;

    std::list<std::string> find(name_t prefix) const;

private:

    // Data member
    std::map<std::string, std::forward_list<FunctionCaller*>> functions;
};
} // namespace egli

#endif // EGLI_DETAIL_FUNCTIONTABLE_H_INCLUDED
