#include <iostream>
using namespace std;

// xor will represent one different bit between A and B. We need to count the number of bits that are 1.
int bitSwapRequired(int a, int b){
	int count = 0;
	for(int c = a^b; c != 0; c >>= 1){
		count += c&1;
	}
	return count;
}

int main(){
	int a = 7, b = 14;
	cout<<bitSwapRequired(a, b)<<endl;
	return 0;
}