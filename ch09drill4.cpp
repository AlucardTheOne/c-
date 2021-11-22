#include "std_lib_facilities.h"

namespace UDChrono {

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

Month operator++(Month& m)
{
	m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}

ostream& operator<<(ostream& os, const Date& d) // ez a user define miatt kell a hibakezeles erdekeben valamint a kiiratott datumformaban esztetika miatt.
{
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
}              
