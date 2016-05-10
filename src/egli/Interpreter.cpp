/*! \brief The EGLI interpreter
 *
 * \file Interpreter.cpp
 * \author Patrick Champion
 * \date 10.05.2016
 */

#include "Interpreter.h"
#include "Exception.h"
#include "ProcessingUnit.h"
#include "detail/interface.h"

egli::Interpreter::Interpreter(Data *data_) :
    m_functions(),
    m_parser(),
    m_data(data_)
{
    detail::interfaceBasics(m_functions);
    detail::interfaceBuiltins(m_functions);
    detail::interfaceAlgorithms(m_functions);
}

std::ostream &egli::Interpreter::writer()
{
    checkDataNotNull();
    return data()->preprocessor().stream();
}

size_t egli::Interpreter::available()
{
    checkDataNotNull();
    return data()->preprocessor().available();
}

egli::Statement egli::Interpreter::next()
{
    checkDataNotNull();
    Statement statement = m_parser.parse(data()->preprocessor().next());
    ProcessingUnit::check(statement, functions(), data()->variables());
    ProcessingUnit::process(statement, functions(), data()->variables());
    return statement;
}

egli::Data *egli::Interpreter::data()
{
    return m_data;
}

const egli::Data *egli::Interpreter::data() const
{
    return m_data;
}

void egli::Interpreter::setData(Data *data_)
{
    m_data = data_;
}

egli::FunctionTable &egli::Interpreter::functions()
{
    return m_functions;
}

const egli::FunctionTable &egli::Interpreter::functions() const
{
    return m_functions;
}

void egli::Interpreter::checkDataNotNull() const
{
    if (data() == nullptr)
        throw Exception("no data", "egli::Interpreter::checkDataNotNull");
}
