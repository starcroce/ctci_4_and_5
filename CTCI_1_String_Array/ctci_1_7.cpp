	#include <iostream>
#include <cstdio>
using namespace std;

void setZero(int a[][3], int m, int n){
	bool row[m];
	bool colum[n];
	for(int i=0; i<m; i++){
		row[i] = false;
	}
	for(int i=0; i<n; i++){
		colum[i] = false;
	}	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(a[i][j] == 0){
				row[i] = true;
				colum[j] = true;
			}
		}
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(row[i] || colum[j])
				a[i][j] = 0;
		}
	}
}

int main(){
	int a[2][3] = {
		{1,0,2},
		{0,1,1}
	};
	int m = 2, n = 3;
	setZero(a, m, n);
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
	return 0;
}