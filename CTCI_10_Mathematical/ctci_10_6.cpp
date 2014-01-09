#include <iostream>
#include <cmath>
#include <map>
#include <ctime>
#include <cstdlib>
using namespace std;

const double eps = 0.0001;

struct point{
	double x, y;
};

class line{
public:
	double slope, yIntercept;
	line(){};
	line(point p, point q){
		if(abs(p.x-q.x) > eps){
			slope = (p.y-q.y)/(p.x-q.x);
			yIntercept = p.y-slope*p.x;
		}
	}
	void printLine(){
		cout<<"y = "<<slope<<"x+"<<yIntercept<<endl;
	}
};

bool operator < (const line &l1, const line &l2){
	return l1.slope < l2.slope;
}

bool equal(double a, double b){
	return abs(a-b) < eps;
}

bool operator == (const line &l1, const line &l2){
	if(equal(l1.slope, l2.slope) && equal(l1.yIntercept, l2.yIntercept))
		return true;
	else
		return false;
}

line findBestLine(point *p, int pointNum){
	line bestline;
	bool flag = true;
	map<line, int> lineCount;
	// there are total n^2 lines and we try to get the lines have the same slope and yIntercept
	// use map to store the lines
    for(int i=0; i<pointNum; i++){
		for(int j=i+1; j<pointNum; j++){
			line l = line(p[i], p[j]);
			if(lineCount.find(l) == lineCount.end())
				lineCount[l] = 0;
			lineCount[l]++;
			if(flag){
				bestline = l;
				flag = false;
			}
			else{
				if(lineCount[l] > lineCount[bestline])
					bestline = l;
			}
		}
	}
	cout<<lineCount[bestline]<<endl;
	return bestline;
}

int main(){
	srand((unsigned)time(0));
	int graphSize = 10;
	int pointNum = 300;
	point *p = new point[pointNum];
	for(int i=0; i<pointNum; i++){
		p[i].x = rand()/double(RAND_MAX)*graphSize;
		p[i].y = rand()/double(RAND_MAX)*graphSize;
	}
	line l = findBestLine(p, pointNum);
	l.printLine();
	return 0;
}