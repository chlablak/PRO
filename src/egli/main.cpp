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

struct data { int first; int second; int third; };

/*! \brief main
 *
 * \return 0
 *
 */
int main()
{
//    string input = "caca";
//    egli::Parser p;
//    try {
//        egli::detail::Statement statement = p.parse(input);
//    } catch (const egli::Exception &e) {
//        cout << e.what() << endl;
//    }

    using boost::spirit::qi::int_;
    using boost::spirit::qi::ascii::char_;
    using boost::spirit::qi::_val;
    using boost::spirit::qi::_1;
    using boost::spirit::qi::attr;
    using boost::spirit::qi::omit;
    using boost::spirit::qi::rule;
    using boost::phoenix::bind;

    using it = string::const_iterator;

    rule<it, data()> r = int_[bind(&data::first, _val) = _1]
        >> ((':' >> int_) | (omit[-char_(':')] >> attr(0)))[bind(&data::second, _val) = _1]
        >> ((':' >> int_) | (omit[-char_(':')] >> attr(0)))[bind(&data::third, _val) = _1];

    string in = ":2:3";
    data dst = {-1, -1, -1};
    bool s = boost::spirit::qi::parse(in.cbegin(), in.cend(), r, dst);

    cout << s << ":" << dst.first << "," << dst.second << "," << dst.third << endl;

    return 0;
}
