#include <iostream>
#include <cmath>
using namespace std;

double eps = 0.000001;

class line{
public:
	double slope;
	double yIntercept;
	line(double s, double y){
		slope = s;
		yIntercept = y;
	}
};

bool intersect(line l1, line l2){
	return abs(l1.slope - l2.slope) > eps || abs(l1.yIntercept - l2.yIntercept) < eps;
}

int main(){
	line l1 = line(1.0, 1.0);
	line l2 = line(2.0, 2.0);
	line l3 = line(1.0, 2.0);
	cout<<intersect(l1, l2)<<" "<<intersect(l1, l3)<<endl;
	return 0;
}