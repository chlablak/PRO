/*! \brief Data passed to the interpreter
 *
 * \file Data.cpp
 * \author Patrick Champion
 * \10.05.2016
 */

#include "Data.h"

egli::Data::Data() :
    m_variables(),
    m_preprocessor()
{}

egli::VariableTable &egli::Data::variables()
{
    return m_variables;
}

const egli::VariableTable &egli::Data::variables() const
{
    return m_variables;
}

egli::detail::Preprocessor &egli::Data::preprocessor()
{
    return m_preprocessor;
}
