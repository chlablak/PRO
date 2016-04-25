/*! \brief Exception base class
 *
 * \file Exception.h
 * \author Patrick Champion
 * \date 20.04.2016
 */

#ifndef EGLI_EXCEPTION_H_INCLUDED
#define EGLI_EXCEPTION_H_INCLUDED

#include <stdexcept>
#include <string>

namespace egli
{
class Exception :
    public std::runtime_error
{
public:

    /*! \brief Constructor
     *
     * \param message - Message about the error
     * \param who - Who is the origin of the error
     * \param where - Where the error appeared
     */
    Exception(const std::string &message = "",
              const std::string &who = "",
              const std::string &where = "");

    /*! \brief Destructor
     */
    virtual ~Exception();
};
} // namespace egli

#endif // EGLI_EXCEPTION_H_INCLUDED
