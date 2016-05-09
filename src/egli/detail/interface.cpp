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
    table.interface("__edge_create", basics::__edge_create);
    table.interface("__vertex_create", basics::__vertex_create);
    table.interface("__negate", basics::__negate_i);
    table.interface("__negate", basics::__negate_f);
    table.interface("__negate", basics::__negate_n);
}

void egli::detail::interfaceBuiltins(FunctionTable &table)
{
    table.interface("toString", builtins::toString_a);
    table.interface("toString", builtins::toString_b);
    table.interface("toString", builtins::toString_e);
    table.interface("toString", builtins::toString_f);
    //table.interface("toString", builtins::toString_g);
    table.interface("toString", builtins::toString_i);
    table.interface("toString", builtins::toString_n);
    table.interface("toString", builtins::toString_s);
    table.interface("toString", builtins::toString_v);
}

void egli::detail::interfaceAlgorithms(FunctionTable &table)
{

}
