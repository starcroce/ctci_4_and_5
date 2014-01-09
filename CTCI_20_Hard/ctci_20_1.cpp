#include <iostream>
using namespace std;

// recursive solution
int add1(int a, int b){
	if(b == 0)
		return a;
	// add two binary number without carry, bit[i] will be 0 if it in a and b are both 0 or both 1, this is XOR
	int sum = a^b; // sum with out carry
	// bit[i] will be 1 if bit[i-1] in a and b are both 1, this is AND and shifted
	int carry = (a&b)<<1;
	return add1(sum, carry); // add the sum and carry
}

// non-recursive solution
int add2(int a, int b){
	int sum, carry;
	while(b != 0){
		sum = a^b;
		carry = (a&b)<<1;
		a = sum;
		b = carry;
	}
	return a;
}

int main(){
	int a = 70, b = -120;
	cout<<add1(a, b)<<" "<<add2(a, b)<<endl;
	return 0;
}