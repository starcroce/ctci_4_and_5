#include <iostream>
using namespace std;

// recursive solution
int recFibo(int n){
	if(n == 0)
		return 0;
	else if(n == 1)
		return 1;
	else if(n > 1)
		return recFibo(n-1)+recFibo(n-2);
	else
		return -1;
}

// iterative solution
int iterFibo(int n){
	if(n == 0)
		return 0;
	if(n < 0)
		return -1;
	int a = 1, b = 1;
	for(int i=3; i<=n; i++){
		int c = a+b;
		a = b;
		b = c;
	}
	return b;
}

int main(){
	for(int i=0; i<20; i++){
		cout<<recFibo(i)<<" ";
	}
	cout<<endl;
	for(int i=0; i<20; i++){
		cout<<iterFibo(i)<<" ";
	}
	cout<<endl;
	return 0;
}