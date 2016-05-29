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
    table.interface("toString", builtins::toString_a);
    table.interface("toString", builtins::toString_b);
    table.interface("toString", builtins::toString_e);
    table.interface("toString", builtins::toString_i); // i before f
    table.interface("toString", builtins::toString_f);
    table.interface("toString", builtins::toString_g);
    table.interface("toString", builtins::toString_n);
    table.interface("toString", builtins::toString_s);
    table.interface("toString", builtins::toString_v);
    table.interface("typeOf", builtins::typeOf_a);
    table.interface("typeOf", builtins::typeOf_b);
    table.interface("typeOf", builtins::typeOf_e);
    table.interface("typeOf", builtins::typeOf_i); // i before f
    table.interface("typeOf", builtins::typeOf_f);
    table.interface("typeOf", builtins::typeOf_g);
    table.interface("typeOf", builtins::typeOf_n);
    table.interface("typeOf", builtins::typeOf_s);
    table.interface("typeOf", builtins::typeOf_v);
    table.interface("er", builtins::originalErdosRenyi);
    table.interface("size", builtins::size_a);
    table.interface("size", builtins::size_g);
}

void egli::detail::interfaceAlgorithms(FunctionTable &table)
{
    table.interface("bfs", algorithms::bfs);
    table.interface("dfs", algorithms::dfs);
    table.interface("cc", algorithms::cc);
    table.interface("tarjan", algorithms::tarjan);
    table.interface("kruskal", algorithms::kruskal);
//    table.interface("prim", algorithms::prim_1);
//    table.interface("prim", algorithms::prim_2);
    table.interface("isConnected", algorithms::isConnected);
    table.interface("isDirected", algorithms::isDirected);
    table.interface("isEmpty", algorithms::isEmpty);
    table.interface("isNegativeWeighted", algorithms::isNegativeWeighted);
    table.interface("isNull", algorithms::isNull);
    table.interface("isPlanar", algorithms::isPlanar);
    table.interface("isSimple", algorithms::isSimple);
    table.interface("isStronglyConnected", algorithms::isStronglyConnected);
    table.interface("isWeighted", algorithms::isWeighted);
    table.interface("bellmanFord", algorithms::bellmanFord);
    table.interface("detectCycle", algorithms::detectCycle);
    table.interface("dijkstra", algorithms::dijkstra);
    table.interface("topologicalSort", algorithms::topologicalSort);
}
