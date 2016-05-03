/*! \brief Statement processing unit class
 *
 * \file ProcessingUnit.h
 * \author Patrick Champion
 * \date 02.05.2016
 */

#ifndef EGLI_PROCESSINGUNIT_H_INCLUDED
#define EGLI_PROCESSINGUNIT_H_INCLUDED

#include "Statement.h"
#include "FunctionTable.h"
#include "VariableTable.h"

namespace egli
{
/*! \brief Statement processing unit
 */
class ProcessingUnit
{
public:

    static void check(const Statement &statement,
                      const FunctionTable &functions,
                      const VariableTable &variables);

    static void process(Statement &statement,
                        const FunctionTable &functions,
                        VariableTable &variables);

private:

    static void checkFunction(const Statement &statement,
                              const FunctionTable &functions,
                              const VariableTable &variables);

    static void processStatement(Statement &statement,
                                 const FunctionTable &functions,
                                 VariableTable &variables);

    static void processAssignation(Statement &statement,
                                   VariableTable &variables);

    static void processArray(Statement &statement,
                             VariableTable &variables);

    static void processConstant(Statement &statement,
                                VariableTable &variables);

    static void processFunction(Statement &statement,
                                const FunctionTable &functions,
                                VariableTable &variables);
};
} // namespace egli

#endif // EGLI_PROCESSINGUNIT_H_INCLUDED
