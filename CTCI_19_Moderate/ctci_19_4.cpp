#include <iostream>
using namespace std;

// without using any if-else or comparison operator
int getMax(int a, int b){
	int c = a-b;
	// k is the most significant bit of c
	int k = (c>>31)&(0x1);
	// if a>b, k=1; else k=0; return a-k*(a-b)
	int max = a-k*c;
	return max;
}

int main(){
	cout<<getMax(5, 10)<<endl;
	return 0;
}