#include <iostream>
using namespace std;

void swap(int a, int b){
	a = b-a;
	b = b-a;
	a = a+b;
	cout<<a<<" "<<b<<endl;
}

void swap1(int a, int b){
	a = a^b;
	b = a^b;
	a = a^b;
	cout<<a<<" "<<b<<endl;
}

int main(){
	int a = 1, b = 2;
	swap(a, b);
	swap1(a, b);
	return 0;
}