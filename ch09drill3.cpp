#include "std_lib_facilities.h"

class Date {
    int y, m, d;                    // year, month, day
public:
    Date(int yy, int mm, int dd);   // ez a valid y m d re vonatkozik es vizsgalja
    void add_day(int n);            // ez pedig a hozzadando napokra hivatkozik
    int month() const { return m; }
    int day() const { return d; }
    int year() const { return y; }
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

void Date::add_day(int n)
{ 
	// minden honapot 31 naposnak veszunk
    int n_d = n % 31;          // a honapbol hatralevo napok a datum novelesehez
    int n_m = (n / 31) % 12;   // az evbol hatralevo honapok a datum novelesehez
    int n_y = n / (31*12);     // az evek a noveleshez

    y += n_y; // ertelemszeruen az evhez az evhez krealt valtot		
    m += n_m; // ertelemszeruen a honaphoz az honaphoz krealt valtot - Hasznaljuk
    d += n_d; // ertelemszeruen az npahoz a naphoz krealt valtot 	

    if (d > 31){
		++m; d -= 30;
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
    return os << '(' << d.year()
              << ',' << d.month()
              << ',' << d.day() << ')';
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
