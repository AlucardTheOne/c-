#include "std_lib_facilities.h"

void swap_v(int a, int b){
	int temp = a; a=b; b=temp;
}
void swap_r(int& a, int& b){
	int temp = a; a=b; b=temp;
}
/*void swap_cr(const int&a,const int&b){
	int temp; temp=a; a=b; b=temp;
}*/
int main()
{
	int x = 7;
	int y = 9;
	swap_r(x,y);
	cout << "x: 7, y:9 , after swap: x: " << x << " y: " << y << endl;
	swap_v(7,9);
	cout << "compiled, swapped" << endl;
	const int cx = 7;
	const int cy = 9;
	swap_v(cx,cy);
	cout << "can't be swapped because of the constant being" << endl;
	swap_v(7.7,9.9);
	cout << "can't be swapped because of double type" << endl;
	double dx = 7.7;
	double dy = 9.9;
	swap_v(dx,dy);
	cout << "can't be swapped because of double type" << endl;
	swap_v(7.7,9.9);
	cout << "can't be swapped because of double type" << endl;
	return 0;
}