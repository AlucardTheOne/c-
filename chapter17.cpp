#include "std_lib_facilities.h"
void print_array10(ostream& os, int* a){
	for(int i=0;i<10;i++)
		os << a[i] << ' ';
	os << endl;
}
void print_array(ostream& os, int* a, int n){
	for(int i=0;i<n;i++)
		os << a[i] << ' ';
	os << endl;
}
void print_vector(ostream& os, vector<int> v){
	for(int i=0;i<v.size();i++)
		os << v[i] << ' ';
	os << endl;
}




int main(){
	int* array = new int[10];
	cout << array[0] << endl;
	print_array10(cout, array);
	delete[] array;

	int* hehej = new int[10];
	for(int i=0;i<10;i++){
		hehej[i] = i +100;
	}
	print_array(cout, hehej, 10);
	int* hehej2 = new int[20];
	for(int i=0;i<20;i++){
		hehej2[i] = i +100;
	}
	print_array(cout, hehej2, 20);
 	delete[] hehej, hehej2;
 	cout << "hehej" << endl;
 	vector<int> vektor(10);
 	vector<int> hehej3(10);
 	vector<int> hehej4(20);
 	for(int i=0;i<vektor.size();i++){
		vektor[i] = i +100;
	}
	for(int i=0;i<hehej3.size();i++){
		hehej3[i] = i +100;
	}
	for(int i=0;i<hehej4.size();i++){
		hehej4[i] = i +100;
	}
 	print_vector(cout,vektor);
 	print_vector(cout,hehej3);
 	print_vector(cout,hehej4);

 	int* hehe = new int(7);
 	int* p1 = hehe;
 	cout << p1 << ' ' << *hehe << endl;
 	int* sevenints = new int[7];

 	for(int i=0;i<7;i++){
 		sevenints[i] = pow(2,i);
 		cout << sevenints[i] << ' ' ;
 	}

 	int* p2 = sevenints;
 	int* p3 = p2;
 	p1 = p2;
 	p3 = p2;
 	cout << p1 << ' ' << p2 << ' ' << *p1 << ' ' << *p2 << endl;
 	cout << "p2 cime: " << p2 << endl;
 	cout << "p2 2.elemének a cime: " << &p2[1] << endl;
 	delete [] p1,p2,p3,hehe, sevenints;

 	int* tenints = new int[10];
 	for(int i=0;i<10;i++){
 		tenints[i] = pow(2,i);
 	}
 	p1 = tenints;
 	int* tenints2 = new int[10];
 	p2 = tenints2;
 	for(int i=0;i<10;i++)
 		tenints2[i] = tenints[i];


 	vector<int> tizint1(10);
 	for(int i=0;i<tizint1.size();i++){
 		tizint1[i] = pow(2,i);
 	}
 	int* p4 = tizint1.data();
 	vector<int> tizint2(10);
 	int* p5 = tizint2.data();
 	for(int i=0;i<tizint2.size();i++)
 		tizint2[i] = tizint1[i];
	return 0;
}