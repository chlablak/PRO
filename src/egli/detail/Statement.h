/*! \brief Statements generated from the Parser
 *
 * \file Statement.h
 * \author Patrick Champion
 * \date 19.04.2016
 *
 */

#ifndef EGLI_DETAIL_STATEMENT_H_INCLUDED
#define EGLI_DETAIL_STATEMENT_H_INCLUDED

#include <string>
#include <vector>

namespace egli
{
namespace detail
{
struct Statement
{
    /*! \brief Type of statement
     */
    enum class Type
    {
        None,           /*!< No statement */
        Assignation,    /*!< Assignation and declaration of a variable */
        Array,          /*!< Creation of an Array */
        Constant,       /*!< Litteral constant (number, string, ...) */
        Function,       /*!< Function call */
        Variable        /*!< Access to the value of a variable */
    };

    // Data members
    Type type;                          /*!< Type of the statement */
    std::string value;                  /*!< Value of the statement */
    std::vector<Statement> parameters;  /*!< Parameters of the statement */

    /*! \brief Constructor
     *
     * \param type - Type of the statement
     * \param value - Value of the statement
     * \param parameters - Parameters of the statement
     *
     */
    Statement(Type type = Type::None,
              const std::string &value = "",
              const std::vector<Statement> &parameters = {});
};
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_STATEMENT_H_INCLUDED
