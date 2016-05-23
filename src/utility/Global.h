#ifndef GLOBAL_H
#define GLOBAL_H

#define UNUSED(arg) (void)arg;

#include <string>
#include <sstream>

namespace utility
{
    template < typename T > std::string toString( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

#endif