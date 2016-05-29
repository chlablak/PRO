/*! \brief Remove space in the output stream
 *
 * \file Preprocessor.h
 * \author Patrick Champion
 * \date 28.04.2016
 */

#ifndef EGLI_DETAIL_PREPROCESSOR_H_INCLUDED
#define EGLI_DETAIL_PREPROCESSOR_H_INCLUDED

#include <iostream>
#include <streambuf>
#include <string>
#include <list>

namespace egli
{
namespace detail
{
/*! \brief Filter buffer that ignore std::isspace() characters
 */
class PreprocessorBuffer :
    public std::streambuf
{
public:

    /*! \brief Constructor
     *
     * \param delimiter - delimiter of the statement
     */
    PreprocessorBuffer(char delimiter);

    /*! \brief Destructor
     */
    virtual ~PreprocessorBuffer();

    /*! \brief Write ch to the underlying buffer
     *
     * \param ch - the character to write
     * \return ch
     */
    virtual int_type overflow(int_type ch);

    /*! \brief Return the underlying buffer contents, and clear it
     *
     * \return The current buffer content
     */
    std::string str();

private:

    // data members
    std::string m_buffer;
    char m_delimiter;
    bool m_quoted;
};

/*! \brief The preprocessor class (stream)
 * \note Uses PreprocessorBuffer for filtering
 */
class Preprocessor
{
public:

    /*! \brief Constructor
     *
     * \param delimiter - the statement delimiter
     */
    Preprocessor(char delimiter = ';');

    // std::iostream is not copyable
    Preprocessor(const Preprocessor&) = delete;
    Preprocessor &operator=(const Preprocessor&) = delete;

    /*! \brief Return the underlying output stream
     *
     * \return A reference to the stream
     */
    std::ostream &stream();

    /*! \brief Return the number of statements available
     *
     * \return Number of statement available
     */
    size_t available();

    /*! \brief Get the next statement available
     *
     * \return The next statement
     *
     * \throw Exception if available() == 0
     */
    std::string next();

    /*! \brief Clear the stream and all queued statements
     */
    void clear();

    /*! \brief Get the raw data contained
     *
     * \return All statement writed
     */
    std::string raw() const;

private:

    // Extract statements from the buffer and put them in the queue
    void sync();

    // data members
    mutable PreprocessorBuffer m_buffer; // mutable for raw() method
    mutable std::ostream m_stream;       // mutable for raw() method
    std::list<std::string> m_queue;
    char m_delimiter;
};
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_PREPROCESSOR_H_INCLUDED
