#include <iostream>
#include <string>
using namespace std;

struct result{
	int hits;
	int pseudoHits;
};

result estimate(string guess, string solution){
	result res;
	res.hits = 0;
	res.pseudoHits = 0;
	int solutionMask = 0;
	// get a bit mask
	for(int i=0; i<4; i++){
		solutionMask |= 1<<(solution.at(i)-'A');
	}
	cout<<solutionMask<<endl;
	for(int i=0; i<4; i++){
		if(guess.at(i) == solution.at(i))
			res.hits++;
		// if there were no same color, it would be 0
		// if there is a pseduo hit, the same pos will be 1
		else if(solutionMask & (1<<(guess.at(i)-'A'))){
			int tmp = 1<<(guess.at(i)-'A');
			// 131138, 131072
			// 100000000001000010
			// 100000000000000000
			cout<<tmp<<endl;
			res.pseudoHits++;
		}
	}
	return res;
}

int main(){
	string solution = "RGGB";
	string guess = "YRGB";
	result res = estimate(guess, solution);
	cout<<res.hits<<" "<<res.pseudoHits<<endl;
	return 0;
}