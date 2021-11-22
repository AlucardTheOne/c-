#include "../../std_lib_facilities.h"

struct Date {
    int y;      // year
    int m;      // month in year
    int d;      // day of month
};

void init_day(Date& dd, int y, int m, int d) // a datum valodisagarol gyozodunk meg nagyon basic atvizsgalassal
{
	if (d < 0 || d > 31 )
		error("invalid day");
	if (m < 0 || m > 12 )
		error ("invalid month");

	dd.y = y;
	dd.m = m;
	dd.d = d;
}

void add_day(Date& dd, int n) // az érték lehet negativ is meg kell gyozodni hogy a felhasznalo barmit beir jo legyen
{
	dd.d += n; 

		if (dd.d > 31){
			++dd.m; dd.d -= 30;
		}
		if (dd.d < 1){
		 	--dd.m; dd.d += 31; 
		}
		if (dd.m > 12){
			++dd.y; dd.m -=11;
		}
		if (dd.m < 1){
		 	--dd.y; dd.m += 12; 
		}

}

ostream& operator<<(ostream& os, const Date& d) // 
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}              

int main()
try
{
    Date today;
    init_day(today, 1978,6,25);

    Date tomorrow{today};
    add_day(tomorrow, 1);

    cout <<"Today : "<< today <<  endl;
    cout <<"Tomorrow : "<< tomorrow << endl;

    Date invalid;
    init_day(invalid, 1978,13,-1);
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!\n";
    return 2;
}