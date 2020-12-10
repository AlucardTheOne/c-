#include "std_lib_facilities.h"

int main(){
	
	string first_name = "";
	cout << "Enter the name of the person you want to write to" << endl;
	cin >> first_name;
	cout << "Dear " << first_name << "," << endl;
	cout << "\tHow are you? I am fine. I miss you." << endl;
	string friend_name = "";
	cout << "Enter your friends name!" << endl;
	cin >> friend_name;
	cout << "Have you seen " << friend_name << " lately?" << endl;
	char friend_sex = 0;
	cout << "Enter your friends sex!(m: for male, f: for female)" << endl;
	cin >> friend_sex;
	if(friend_sex == 'm')
		cout << "If you see " << friend_name << " coming please ask him to call me" << endl;
	if(friend_sex == 'f')
		cout << "If you see " << friend_name << " coming please ask her to call me" << endl;
	cout << "Enter the age of the recipient!" << endl;
	int age = 0;
	cin >> age;
	if(age < 0 || age >= 110)
		simple_error("you're kidding!");
	cout << "I hear you just had a birthday and you are " << age << " years old." << endl;
	if(age <= 12)
		cout << "Next year you will be " << age+1 << endl;
	if(age == 17)
		cout << "Next year you will be able to vote." << endl;
	if(age > 70)
		cout << "I hope you are enjoying retirement. " << endl;
	cout << "Yours sincerely," << endl << endl;
	cout << "Kiss László" << endl;
	return 0;
}