#include "std_lib_facilities.h"

const vector<string> months = 
{
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
};

enum class Month {
	jan, feb, mar, apr, may, june, july, aug, sept, oct, nov, dec
};

Month operator++(Month& m)
{
	m = (m==Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}

ostream& operator<<(ostream& os, Month m)
{
	return os << months[int(m)];
}

class Date {
	int year;
	Month month;
	int day;
public:
	class Invalid {};
	Date(int y, Month m, int d): year(y), month(m), day(d) { if (!is_valid()) throw Invalid {}; }
	bool is_valid();
	void add_day(int n);
	int get_year() const { return year; }
	Month get_month() const { return month; }
	int get_day() const { return day; }
};
ostream& operator<<(ostream& os, Date& date){
	return os << date.get_year() << '.' << date.get_month() << '.' << date.get_day();
}

bool Date::is_valid()
{
	if (year < 0 || day < 1 || day > 31) return false;
	return true;
}

void Date::add_day(int n)
{
	day += n;
	if (day > 31) 
	{
		++month;
		day -= 31;
		if (month == Month::jan)
		{
			year++;
		}
	}
}

int main()
try {
	Date today {1978, Month::june, 25};

	cout << "Today: " << today << endl;
	Date tomorrow = {today};
	tomorrow.add_day(1);
	cout << "Tomorrow: " << tomorrow << endl;
	Date invalid {2004, Month::june, -5};
	cout << invalid << endl;

	return 0;

} catch (Date::Invalid) {
	cout << "Error: Invalid date\n";
	return 1; 
} catch (exception& e) {
	cout << "Error: " << e.what() << endl;
	return 2;
}