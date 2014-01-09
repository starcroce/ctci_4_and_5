#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

string getBinary(string str){
	int pointPos = str.find('.', 0);
	int intPart = atoi(str.substr(0, pointPos).c_str());
	double decPart = atof(str.substr(pointPos, str.length()-pointPos).c_str());
	string intStr = "", decStr = "";
	while(intPart > 0){
		if(intPart & 1){
			intStr = "1"+intStr;
		}
		else{
			intStr = "0"+intStr;
		}
		intPart >>= 1;
	}
	while(decPart > 0){
		decPart *= 2;
		if(decPart >= 1){
			decStr += "1";
			decPart -= 1;
		}
		else
			decStr += "0";
	}
	return intStr+"."+decStr;
}

int main(){
	string str = "12.25";
	cout<<getBinary(str)<<endl;
	return 0;
}