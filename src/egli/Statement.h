/*! \brief Statements generated from the Parser
 *
 * \file Statement.h
 * \author Patrick Champion
 * \date 19.04.2016
 */

#ifndef EGLI_STATEMENT_H_INCLUDED
#define EGLI_STATEMENT_H_INCLUDED

#include <string>
#include <vector>

namespace egli
{
/*! \brief Statement (tree)
 */
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

    /*! \brief Constant type
     */
    enum class ConstantType
    {
        Unused,         /*!< Not used */
        Boolean,        /*!< Boolean constant */
        Float,          /*!< Float constant */
        Integer,        /*!< Integer constant */
        String          /*!< String constant */
    };

    // Data members
    Type type;                          /*!< Type of the statement */
    ConstantType constantType;          /*!< Constant type */
    std::string value;                  /*!< Value of the statement */
    std::vector<Statement> parameters;  /*!< Parameters of the statement */

    /*! \brief Constructor
     *
     * \param type - Type of the statement
     * \param value - Value of the statement
     * \param parameters - Parameters of the statement
     * \param constantType - The constant type
     */
    Statement(Type type = Type::None,
              const std::string &value = "",
              const std::vector<Statement> &parameters = {},
              ConstantType constantType = ConstantType::Unused);

    /*! \brief Constructor
     *
     * \param constantType - The constant type
     * \param value - Value of the constant
     */
    Statement(ConstantType constantType, const std::string &value);

    /*! \brief Transform the statement in a Variable statement
     *
     * \param value - The Variable value
     */
    void transformToVariable(const std::string &value);
};
} // namespace egli

#endif // EGLI_STATEMENT_H_INCLUDED
