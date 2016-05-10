/*! \brief The EGLI interpreter
 *
 * \file Interpreter.h
 * \author Patrick Champion
 * \date 10.05.2016
 */

#ifndef EGLI_INTERPRETER_H_INCLUDED
#define EGLI_INTERPRETER_H_INCLUDED

#include "FunctionTable.h"
#include "Data.h"
#include "Parser.h"
#include "Statement.h"

namespace egli
{
/*! \brief The EGLI Interpreter
 */
class Interpreter
{
public:

    /*! \brief Constructor
     *
     * \param data - An associated Data
     *
     * \note This class does not handle the Data* deletion
     */
    Interpreter(Data *data = nullptr);

    // Many data members are not copyable
    Interpreter(const Interpreter&) = delete;
    Interpreter &operator=(const Interpreter&) = delete;

    /*! \brief Get the preprocessor output stream
     *
     * \return the std::ostream
     *
     * \throw Exception if !data()
     */
    std::ostream &writer();

    /*! \brief Get the number of statement available for processing
     *
     * \return The number of queued statement
     *
     * \throw Exception if !data()
     */
    size_t available();

    /*! \brief Process the next available statement
     *
     * \return The resulting statement
     *
     * \throw Exception if !data() or if an error occurs during the process
     */
    Statement next();

    /*! \brief Get the current Data
     *
     * \return The current Data
     */
    Data *data();

    /*! \brief Get the current Data (const)
     *
     * \return The current Data
     */
    const Data *data() const;

    /*! \brief Set the current Data
     *
     * \param data - the new associated Data
     *
     * \note This class does not handle the Data* deletion
     */
    void setData(Data *data);

    /*! \brief Get the underlying FunctionTable
     *
     * \return The functions table
     */
    FunctionTable &functions();

    /*! \brief Get the underlying FunctionTable (const)
     *
     * \return The functions table
     */
    const FunctionTable &functions() const;

private:

    // throw Exception if data() == nullptr
    void checkDataNotNull() const;

    // data members
    FunctionTable m_functions;
    Parser m_parser;
    Data *m_data;
};
} // namespace egli

#endif // EGLI_INTERPRETER_H_INCLUDED
