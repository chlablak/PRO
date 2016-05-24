/*! \brief Generate a number in [0;1]
 *
 * \file uniform01.cpp
 * \author Patrick Champion
 * \date 24.05.2016
 */

#include <ctime>
#include <random>
#include "uniform01.h"

// local variable
namespace
{
std::minstd_rand gen(std::time(nullptr));
std::uniform_real_distribution<double> dis(0., 1.);
}

double utility::uniform01()
{
    return dis(gen);
}
