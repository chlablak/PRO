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
    table.interface("toString", builtins::toString_f);
    table.interface("toString", builtins::toString_g);
    table.interface("toString", builtins::toString_i);
    table.interface("toString", builtins::toString_n);
    table.interface("toString", builtins::toString_s);
    table.interface("toString", builtins::toString_v);
}

void egli::detail::interfaceAlgorithms(FunctionTable &table)
{

}
