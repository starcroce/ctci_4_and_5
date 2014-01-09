#include <iostream>
using namespace std;

int makeChange(int n, int denom){
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