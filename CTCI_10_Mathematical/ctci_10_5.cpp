#include <iostream>
#include <vector>
using namespace std;

class square{
public:
	double left;
	double top;
	double size;
	square(double l, double t, double s){
		left = l;
		top = t;
		size = s;
	}
	vector<double> middle(){
		vector<double> middle(2);
		middle.at(0) = left+size/2;
		middle.at(1) = top-size/2;
		return middle;
	}
};

int main(){
	square s1 = square(0.0, 2.0, 2.0);
	square s2 = square(2.0, 4.0, 2.0);
	vector<double> m1 = s1.middle();
	vector<double> m2 = s2.middle();
	double x1 = m1.at(0), y1 = m1.at(1);
	double x2 = m2.at(0), y2 = m2.at(1);
	double k = (y1-y2)/(x1-x2);
	double b = y1-(x1*(y1-y2))/(x1-x2);
	cout<<"The line is: y = "<<k<<"x+"<<b<<endl;
	return 0;
}