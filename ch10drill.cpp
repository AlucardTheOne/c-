#include "std_lib_facilities.h"

struct Point
{
	int x, y;
};

vector<Point>original_points;
vector<Point>processed_points;

void get_pairs()
{
	int x, y;

while(true)
{
	cin >> x >> y;
	original_points.push_back({x,y});

		if (original_points.size() == 7)
			break;

		/* if (original_points.size() > 7)
			{	cin.clear();
				cout << "Original_points: " << endl;
				for (int i=0; i<original_points.size(); i++)
				{
					cout << original_points[i].x << ";" << original_points[i].y << endl;
				} 
				error("You have already entered 7 pairs of (x,y).");
				
			}
		*/	
		else if (cin.fail()) // if not integer!
		{
			cin.clear();
			cout << "Sorry, that was not a number!\n";
			for (char ch; cin >> ch && !isdigit(ch);); 
		}
	}	
};

void output_pairs()
{
	string filename = "mydata.txt";

	ofstream ost {filename};

	if (!ost) error(filename , "doesn't exist or can't open it.");


	for (int i=0; i<original_points.size(); i++)
	{
		ost << original_points[i].x << ' ' << original_points[i].y << endl;
	}

	
	ost.close();
}

void input_pairs()
{	
	int x, y;

	string filename = "mydata.txt";

	ifstream ist {filename};

	if (!ist) error(filename , "doesn't exist or can't open it.");

	while (ist >> x >> y)
	{
		processed_points.push_back(Point{x,y});
	}
}

void compare_pairs()
{	
	for (int i=0; i<original_points.size(); i++)
	{	
	if ((original_points[i].x !=processed_points[i].x) || (original_points[i].y !=processed_points[i].y))
			error("Something's wrong");
	}	
}

int main()
try 
{
	cout << "Enter 7 pairs of (x,y) : " << endl;

	get_pairs();

	output_pairs();
	input_pairs();

	cout << "Original points: \n";
	for (int i=0; i<original_points.size(); i++)
	{
		cout << original_points[i].x << ' ' << original_points[i].y << endl;
	}

	cout << "Processed points: \n";
	for (int i=0; i<processed_points.size(); i++)
	{
		cout << processed_points[i].x << ' ' << processed_points[i].y << endl;
	}
	

	compare_pairs();
	
}
catch (runtime_error& e){
	cout << "Error : " << e.what() << endl;
	return 1;
}catch (...){
	cout << "Some error: " <<  endl;
	return 2;
}
