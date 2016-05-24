/*! \brief Interface functions
 *
 * \file interface.cpp
 * \author Patrick Champion
 * \date 03.05.2016
 */

#include "interface.h"
#include "interface/basics.h"
#include "interface/builtins.h"
#include "interface/algorithms.h"

void egli::detail::interfaceBasics(FunctionTable &table)
{
    table.interface("__graph_add", basics::__graph_add_a);
    table.interface("__graph_add", basics::__graph_add_e);
    table.interface("__graph_add", basics::__graph_add_v);
    table.interface("__graph_sub", basics::__graph_sub_a);
    table.interface("__graph_sub", basics::__graph_sub_e);
    table.interface("__graph_sub", basics::__graph_sub_v);
    table.interface("__graph_create", basics::__graph_create);
    table.interface("__graph_create", basics::__graph_create_with_shortcut);
    table.interface("__edge_create", basics::__edge_create);
    table.interface("__vertex_create", basics::__vertex_create);
    table.interface("__negate", basics::__negate_i);
    table.interface("__negate", basics::__negate_f);
    table.interface("__negate", basics::__negate_n);
}

void egli::detail::interfaceBuiltins(FunctionTable &table)
{
    table.interface("save", builtins::save);
    table.interface("load", builtins::load);
    table.interface("string", builtins::toString_a);
    table.interface("string", builtins::toString_b);
    table.interface("string", builtins::toString_e);
    table.interface("string", builtins::toString_f);
    table.interface("string", builtins::toString_g);
    table.interface("string", builtins::toString_i);
    table.interface("string", builtins::toString_n);
    table.interface("string", builtins::toString_s);
    table.interface("string", builtins::toString_v);
    table.interface("type", builtins::typeOf_a);
    table.interface("type", builtins::typeOf_b);
    table.interface("type", builtins::typeOf_e);
    table.interface("type", builtins::typeOf_f);
    table.interface("type", builtins::typeOf_g);
    table.interface("type", builtins::typeOf_i);
    table.interface("type", builtins::typeOf_n);
    table.interface("type", builtins::typeOf_s);
    table.interface("type", builtins::typeOf_v);
}

void egli::detail::interfaceAlgorithms(FunctionTable &table)
{
    table.interface("bfs", algorithms::bfs);
    table.interface("dfs", algorithms::dfs);
    table.interface("cc", algorithms::cc);
    table.interface("scc", algorithms::scc);
    table.interface("kruskal", algorithms::kruskal);
}
