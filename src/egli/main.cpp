/*! \brief Unary tests for EGLI interpreter
 *
 * \file main.cpp
 * \author Patrick Champion
 * \date 19.04.2016
 *
 */

#include <iostream>
#include <string>
#include <cassert>

#include "egli.h"

using namespace std;

/*! \brief main
 *
 * \return 0
 *
 */
int main()
{
    string input = "caca";
    egli::Parser p;
    try {
        egli::detail::Statement statement = p.parse(input);
    } catch (const egli::Exception &e) {
        cout << e.what() << endl;
    }

    return 0;
}
