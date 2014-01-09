#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printLastKLines(ifstream &fileIn, int k){
	string line[k];
	int lines = 0;
	string tmp;
	// get line from fileIn and store in tmp
	while(getline(fileIn, tmp)){
		line[lines%k] = tmp;
		lines++; // get the total line of fileIn
	}
	int start, count;
	if(lines < k){
		start = 0;
		count = lines;
	}
	else{
		start = lines%k;
		count = k;
	}
	for(int i=0; i<k; i++){
		cout<<line[(start+i)%k]<<endl;
	}
}

int main(){
	ifstream fileIn("13_1.in");
	int k = 4;
	printLastKLines(fileIn, k);
	fileIn.close();
	return 0;
}