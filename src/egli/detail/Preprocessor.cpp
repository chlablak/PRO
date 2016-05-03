/*! \brief Remove space in the output stream
 *
 * \file Preprocessor.cpp
 * \author Patrick Champion
 * \date 28.04.2016
 */

#include <cctype>
#include <sstream>

#include "Preprocessor.h"
#include "../Exception.h"

egli::detail::PreprocessorBuffer::PreprocessorBuffer(char delimiter) :
    m_buffer(),
    m_delimiter(delimiter),
    m_quoted(false)
{}

egli::detail::PreprocessorBuffer::~PreprocessorBuffer()
{}

egli::detail::PreprocessorBuffer::int_type
    egli::detail::PreprocessorBuffer::overflow(int_type ch)
{
    if (traits_type::eq_int_type(ch, traits_type::eof()))
        return std::streambuf::overflow(ch);
    if (ch == '"')
        m_quoted = !m_quoted;
    if (!std::isspace(ch) || m_quoted) {
        m_buffer.push_back(ch);
        if (ch == m_delimiter)
            m_buffer.push_back('\n');
    }
    return ch;
}

std::string egli::detail::PreprocessorBuffer::str()
{
    std::string tmp = m_buffer;
    m_buffer.clear();
    return tmp;
}

egli::detail::Preprocessor::Preprocessor(char delimiter) :
    m_buffer(delimiter),
    m_stream(&m_buffer),
    m_queue(),
    m_delimiter(delimiter)
{}

std::ostream &egli::detail::Preprocessor::stream()
{
    return m_stream;
}

size_t egli::detail::Preprocessor::available()
{
    sync();
    return m_queue.size();
}

std::string egli::detail::Preprocessor::next()
{
    if(available() == 0) // call sync()
        throw Exception("empty queue", "egli::detail::Preprocessor::next");
    std::string tmp = m_queue.front();
    m_queue.pop_front();
    return tmp;
}

void egli::detail::Preprocessor::sync()
{
    std::string tmp;
    std::istringstream iss(m_buffer.str());
    while (std::getline(iss, tmp))
        m_queue.push_back(tmp);
    if (!m_queue.empty() && m_queue.back().back() != m_delimiter) {
        stream() << m_queue.back();
        m_queue.pop_back();
    }
}
