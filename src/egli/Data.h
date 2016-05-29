/*! \brief Data passed to the interpreter
 *
 * \file Data.h
 * \author Patrick Champion
 * \date 10.05.2016
 */

#ifndef EGLI_DATA_H_INCLUDED
#define EGLI_DATA_H_INCLUDED

#include "VariableTable.h"
#include "detail/Preprocessor.h"

namespace egli
{
/*! \brief Data passed to the interpreter (current state)
 */
class Data
{
public:

    /*! \brief Constructor
     */
    Data();

    // Preprocessor are not copyable
    Data(const Data&) = delete;
    Data &operator=(const Data&) = delete;

    /*! \brief Get the underlying VariableTable
     *
     * \return The variables table
     */
    VariableTable &variables();

    /*! \brief Get the underlying VariableTable (const)
     *
     * \return The variables table
     */
    const VariableTable &variables() const;

    /*! \brief Get the underlying Preprocessor
     *
     * \return The preprocessor
     *
     * \note Not intended to be used directly by the user
     */
    detail::Preprocessor &preprocessor();

    /*! \brief Get the underlying Preprocessor
     *
     * \return The preprocessor
     *
     * \note Not intended to be used directly by the user
     */
    const detail::Preprocessor &preprocessor() const;

    /*! \brief Clear all datas
     */
    void clear();

private:

    // data members
    VariableTable m_variables;
    detail::Preprocessor m_preprocessor;
};
} // namespace egli

#endif // EGLI_DATA_H_INCLUDED
