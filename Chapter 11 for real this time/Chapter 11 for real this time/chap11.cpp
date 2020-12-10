#include "std_lib_facilities.h"

int main()
{
	int birth_year = 2000;

	cout << "Decimal: " << birth_year << '\t' << "Hexadecimal: " << hex << birth_year << '\t' << "Octal: " << oct << birth_year << endl;

	int my_age = 20;

	cout << "My age: " << dec << my_age << endl;

	int a, b, c, d;
	cout << "Please enter 1234 1234 1234 1234" << endl;
	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

	float number = 1234567.89;

	cout << "Defaultfloat: " << defaultfloat << number << endl << "Fixed: " << fixed << number << endl << "Scientific: " << scientific << number << endl;

	//cout setw(n) '|'
	return 0;
}