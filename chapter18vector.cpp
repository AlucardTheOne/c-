#include "std_lib_facilities.h"

vector<int> gv(10);


void feltoltes(vector<int>& vektor){
	for(int i=0;i<vektor.size();i++)
		vektor[i] = pow(2,i);
}

void kiiras(ostream& os, vector<int> vektor){
	for(int i=0; i<vektor.size();i++)
		os << vektor[i] << ' ' ;
	os << endl;
}
int factorial(int f){
	if ( f <= 1) 
        return 1;
    return(f * factorial(f - 1));
}

void f(vector<int> vektor){
	vector<int> lv(vektor.size());
	for(int i=0;i<10;i++)
		lv[i] = gv[i];
	kiiras(cout, lv);
	vector<int> lv2(vektor.size());
	for(int i=0; i<vektor.size();i++)
		lv2[i] = vektor[i];
	kiiras(cout, lv2);

}


int main(){
	feltoltes(gv);
	f(gv);
	vector<int> vv(10);
	for(int i=0;i<10;i++){
		vv[i] = factorial(i+1);
	}
	f(vv);
	return 0;

}