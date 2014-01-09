#include <iostream>
using namespace std;

int countOne(int n){
	int count = 0;
	for(int i=0; i<32; i++){
		if(n & 1){
			count++;
		}
		n >>= 1;
	}
	return count;
}

// n++ or n-- and check if they have the same number of 1 in binary
int next(int n){
	int num = countOne(n);
	if(num == 0 || n == -1){
		return -1;
	}
	for(n++; countOne(n) != num && n != -1; n++);
	if(n == -1){
		return -1;
	}
	return n;
}

int previous(int n){
	int num = countOne(n);
	if(num == 0 || n == -1){
		return -1;
	}
	for(n--; countOne(n) != num && n != -1; n--);
	if(n == -1){
		return -1;
	}
	return n;	
}

int main(){
	int n = -455568;
	cout<<previous(n)<<" "<<next(n)<<endl;
	return 0;
}