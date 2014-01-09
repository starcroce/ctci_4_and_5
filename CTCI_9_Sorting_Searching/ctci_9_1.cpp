#include <iostream>
using namespace std;

void merge(int a[], int b[], int n, int m){
	int k = m+n-1; // index of the last location of merged
	int i = n-1; // index of the last element in b
	int j = m-1; // index of the last element in a
	// starting comparing from the last element and merge a and b
	while(i >= 0 && j >= 0){
		if(a[i] > b[j])
			a[k--] = a[i--];
		else
			a[k--] = b[j--];
	}
	while(j >= 0){
		a[k--] = b[j--];
	}
}

int main(){
	int a[12] = {1, 3, 7, 8, 9};
	int b[] = {2, 4, 5, 6, 10};
	int n = 5, m = 5;
	merge(a, b, 5, 5);
	for(int i=0; i<m+n; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}