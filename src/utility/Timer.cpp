/*! \brief Simple time profiler
 *
 * \file Timer.cpp
 * \author Patrick Champion
 * \date 25.05.2016
 */

#include "Timer.h"

utility::Timer::Timer() :
    m_start(),
    m_stop(),
    m_stopped(true)
{
    reset();
}

void utility::Timer::reset()
{
    m_start = clock_t::now();
    m_stopped = false;
}

void utility::Timer::stop()
{
    m_stop = clock_t::now();
    m_stopped = true;
}

double utility::Timer::elapsed() const
{
    clock_t::time_point tmp = m_stopped ? m_stop : clock_t::now();
    return std::chrono::duration_cast<unit_t>(tmp - m_start).count();
}
