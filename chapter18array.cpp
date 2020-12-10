#include "std_lib_facilities.h"

int* ga = new int[10];


void feltoltes(int* array, int size){
	for(int i=0;i<size;i++)
		array[i] = pow(2,i);
}

void kiiras(ostream& os, int* array, int size){
	for(int i=0; i<size;i++)
		os << array[i] << ' ' ;
	os << endl;
}
int factorial(int f){
	if ( f <= 1) 
        return 1;
    return(f * factorial(f - 1));
}

void f(int* array, int size){
	int* la = new int[10];
	for(int i=0;i<10;i++)
		la[i] = ga[i];
	kiiras(cout, la, 10);
	int* p = new int[size];
	for(int i=0; i<size;i++)
		p[i] = array[i];
	kiiras(cout, p, 10);

	delete [] p;

}


int main(){

	feltoltes(ga,10);
	f(ga,10);
	int* aa = new int[10];
	for(int i=0;i<10;i++){
		aa[i] = factorial(i+1);
	}
	f(aa,10);
	return 0;

}
