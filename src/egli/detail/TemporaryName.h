/*! \brief Generate temporary names
 *
 * \file TemporaryName.h
 * \author Patrick Champion
 * \date 26.04.2016
 */

#ifndef EGLI_DETAIL_TEMPORARYNAME_H_INCLUDED
#define EGLI_DETAIL_TEMPORARYNAME_H_INCLUDED

#include <stack>
#include <string>

namespace egli
{
namespace detail
{
/*! \brief Class for temporary names generation
 */
class TemporaryName
{
public:

    /*! \brief Width of the name
     *
     * \note Name will be of size 2*width+2
     * \note Max level and name per level is 10^width
     */
    static constexpr size_t width = 3;

    /** \brief Constructor
     */
    TemporaryName();

    /** \brief Enter a new level
     */
    void enter();

    /*! \brief Return back to the previous level
     *
     * \note If there is no level left, call enter()
     */
    void leave();

    /** \brief Get the next name
     *
     * \return The next generated name
     */
    std::string next();

    /** \brief Get the current level prefix
     *
     * \return The current level prefix
     */
    std::string prefix() const;

    /*! \brief Reset to the inital default constructed state
     */
    void reset();

private:

    std::stack<size_t> levels;
};
} // namespace detail
} // namespace egli

#endif // EGLI_DETAIL_TEMPORARYNAME_H_INCLUDED
