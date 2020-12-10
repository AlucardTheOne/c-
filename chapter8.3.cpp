#include "std_lib_facilities.h"

namespace X{
	int var;
	void print(){
		cout << var << endl;
	}
}

namespace Y{
	int var;
	void print(){
		cout << var << endl;
	}
}

namespace Z{
	int var;
	void print(){
		cout << var << endl;
	}
}
int main(){

	X::var = 7;
	X::print(); // this will print out 7

	using namespace Y;
	var = 9;
	print(); // this will print out 9
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();  // this will print out 11 because of the scope

	}
	print(); // quitting the scope so it will print out 9 again
	X::print(); //this will print out 7.
}