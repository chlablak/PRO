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

    /*! \brief Check if the statement is valid
     *
     * \param statement - The statement to check
     * \param functions - The functions table
     * \param variables - The variables tables
     *
     * \throw Exception if there is an error
     */
    static void check(const Statement &statement,
                      const FunctionTable &functions,
                      const VariableTable &variables);

    /*! \brief Process the statement
     *
     * \param statement - The statement to process
     * \param functions - The functions table
     * \param variables - The variables tables
     *
     * \throw Exception if there is an error
     */
    static void process(Statement &statement,
                        const FunctionTable &functions,
                        VariableTable &variables);

private:

    // Checking specialized for Function statement
    static void checkFunction(const Statement &statement,
                              const FunctionTable &functions,
                              const VariableTable &variables);

    // Processing dispatcher
    static void processStatement(Statement &statement,
                                 const FunctionTable &functions,
                                 VariableTable &variables);

    // Processing specialzed for Assignation statement
    static void processAssignation(Statement &statement,
                                   VariableTable &variables);

    // Processing specialzed for Array statement
    static void processArray(Statement &statement,
                             VariableTable &variables);

    // Processing specialzed for Constant statement
    static void processConstant(Statement &statement,
                                VariableTable &variables);

    // Processing specialzed for Function statement
    static void processFunction(Statement &statement,
                                const FunctionTable &functions,
                                VariableTable &variables);
};
} // namespace egli

#endif // EGLI_PROCESSINGUNIT_H_INCLUDED
