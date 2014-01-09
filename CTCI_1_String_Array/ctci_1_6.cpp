#include <iostream>
using namespace std;

void swap(int &a, int &b){
	a = a+b;
	b = a-b;
	a = a-b;
}

void rotate(int a[][4], int n){
	// 1 5 9  13
	// 2 6 10 14
	// 3 7 11 15
	// 4 8 12 16
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			swap(a[i][j], a[j][i]);
		}
	}
	// reverse the rotated matrix
	for(int i=0; i<n/2; i++){
		for(int j=0; j<n; j++){
			swap(a[i][j], a[n-i-1][j]);
		}
	}
}

int main(){
	int a[4][4] = {
		{1,2,3,4}, 
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};
	rotate(a, 4);
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}