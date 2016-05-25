/*! \brief Simple time profiler
 *
 * \file Timer.h
 * \author Patrick Champion
 * \date 25.05.2016
 */

#ifndef UTILITY_TIMER_H_INCLUDED
#define UTILITY_TIMER_H_INCLUDED

#include <chrono>

namespace utility
{
/*! \brief Simple timer
 */
class Timer
{
public:

    // Usefuls typedefs
    using clock_t = std::chrono::high_resolution_clock;
    using unit_t = std::chrono::duration<double>; // second

    /*! \brief Constructor
     *
     * \note Call reset()
     */
    Timer();

    /*! \brief Start the Timer
     */
    void reset();

    /*! \brief Stop the Timer
     */
    void stop();

    /*! \brief Get the elapsed time
     *
     * \return The elapsed time in second
     *
     * \note Timer stopped or not, it's work anyway
     */
    double elapsed() const;

private:

    // Data members
    clock_t::time_point m_start;
    clock_t::time_point m_stop;
    bool m_stopped;
};
} // namespace utility

#endif // UTILITY_TIMER_H_INCLUDED
