#include <iostream>
using namespace std;

// to know how many 0s in n!, only need to know how many 5 facs
int numZeros(int n){
	int count = 0;
	if(n < 0)
		return -1;
	// count the number of n/5, then n/25, then n/125...
	for(int i=5; n/i>0; i*=5){
		count += n/i;
	}
	return count;
}

int main(){
	cout<<numZeros(26)<<endl;
	return 0;
}