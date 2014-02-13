#include <iostream>
using namespace std;

int makeChange(int n, int denom){
	// next denom is the largest number it can take next time
	int nextDenom = 0;
	switch(denom){
		case 25:
			nextDenom = 10;
			break;
		case 10:
			nextDenom = 5;
			break;
		case 5:
			nextDenom = 1;
			break;
		case 1:
			return 1;
	}
	int ways = 0;
	// start from 0*25, use others to finish n recursively
	// then from 1*25, use others to finish n resursively
	for(int i=0; i*denom<=n; i++){
		ways += makeChange(n-i*denom, nextDenom);
	}
	return ways;
}

int main(){
	int n = 30;
	cout<<makeChange(n, 25)<<endl;
	return 0;
}