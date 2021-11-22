#include "../../std_lib_facilities.h"

struct Date {
    int y, m, d;                    // year, month, day
    Date(int yy, int mm, int dd);   // ez a valid y m d re vonatkozik es vizsgalja
    void add_day(int n);            // ez pedig a hozzadando napokra hivatkozik
};

Date::Date(int yy, int mm, int dd) //ebben a date structon beluli date fuggvenyre utal hibakezeles az elozohoz hasonlo
{
	if (dd < 0 || dd > 31 )
		error("invalid day");
	if (mm< 0 || mm> 12 )
		error ("invalid month");

    y = yy;       
    m = mm;
    d = dd;
}

void Date::add_day(int n) // a hibakezeles ebben is az elozohoz hasonlo es date structon beluli add day fuggvenyt hivja
{
    d += n; // az n itt is lehet negativ
     
  if (d > 31){
		++m; d -= 30; // nem a megfelelo napot irja ki nagy szam hozzadasa eseten
		}
	if (d < 1){
		--m; d += 31; 
		}
	if (m > 12){
		++y; m -=11;
		}
	if (m < 1){
		--y; m += 12; 
		}
}

ostream& operator<<(ostream& os, const Date& d) // ez a user define miatt kell a hibakezeles erdekeben valamint a kiiratott datumformaban esztetika miatt.
{
    return os << '(' << d.y
              << ',' << d.m
              << ',' << d.d << ')';
}

int main()
try
{
   Date today{1978,6,25};

   Date tomorrow{today};
    tomorrow.add_day(1);

   cout <<"Today : "<< today <<  endl;
   cout <<"Tomorrow : "<< tomorrow << endl;

   Date add_huge{today};
   add_huge.add_day(5000);

   cout <<"Somewhen : "<< add_huge << endl;
   
   Date invalid{1978, -12, 33};

    return 0;
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