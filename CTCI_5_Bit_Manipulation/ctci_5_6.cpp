#include <iostream>
#include <string>
using namespace std;

// mask all odd bits with 10101010 (which is 0xaa), then shift them left to put them in the even bits.
int swapOddEvenBits(int n){
	return ((n & 0xaaaaaaaa)>>1)|((n & 0x55555555)<<1);
}

void printBinary(int n){
	string s = "";
	for(int i=0; i<32 && n!=0; i++, n>>=1){
		if(n & 1){
			s = "1"+s;
		}
		else{
			s = "0"+s;
		}
	}
	cout<<s<<endl;
}

int main(){
	int n = 44;
	printBinary(n);
	printBinary(swapOddEvenBits(n));
	return 0;
}