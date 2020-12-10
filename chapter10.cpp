#include "std_lib_facilities.h"

struct Point{
	int x,y;
};
vector<Point> bekeres(){
	int x,y;
	vector<Point> original_points;
	cout << "Please enter 7 x,y pairs" << endl;
	for(int i=0;i<7;i++){
		cin >> x >> y;
		if(cin)
			original_points.push_back(Point{x,y});
		else if(cin.fail()){
			cin.clear();
			--i;
			cout << "please enter integer" << endl;
			for(char c; cin >> c && !isdigit(c);)
				;
			if(!cin) error("no input");
			cin.unget();
		}
		else
			error("no input");

	}
	cout << "Original points: " << endl;
	for(const auto& point: original_points)
	cout << point.x << ' ' << point.y << endl; 
	return original_points;
}
void outputfilecreating(vector<Point>& original_points){ 
	ofstream outputfilestream {"mydata.txt"};
	if(!outputfilestream) error("no such file or directory");
	for(const auto& point : original_points)
		outputfilestream << point.x << ' ' << point.y << endl;
	outputfilestream.close();

	cout << "good file" << endl;
}
vector<Point> inputfilestreamcreating(){
	ifstream pain{"mydata.txt"};
	if(!pain) error("no such file or directory");
	int x,y;
	vector<Point> processed_points;
	while(pain >> x >> y){
		processed_points.push_back(Point{x,y});
	}
	cout << "Processed points: " << endl;
	for(const auto& point: processed_points)
	cout << point.x << ' ' << point.y << endl; 
	return processed_points;
}
void osszehasonlitas(vector<Point>& egyik, vector<Point>& masik){
	if(egyik.size() != masik.size()){
		cout << "The files are not equivalent" << endl;
		return;
	}
	for(int i=0; i<egyik.size(); i++){
		if(egyik[i].x != masik[i].x || egyik[i].y != masik[i].y){
			cout << "The files are not equivalent" << endl;
			return;
		}
	}
	cout << "The files are equivalent, verynice" << endl;
} 
int main()
	try{
		vector<Point> original_points{bekeres()};
		outputfilecreating(original_points);	
		vector<Point> processed_points{inputfilestreamcreating()};
		osszehasonlitas(original_points,processed_points);





	return 0;

}catch(exception& e){cout << e.what() << endl; 

}

