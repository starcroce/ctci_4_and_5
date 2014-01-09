#include <iostream>
#include <cstring>
using namespace std;

// fetch the jth bit of a[i]
int fetch(int a[], int i, int j){
	return (a[i]>>j)&1;
}

// if we can get the number from the array, if we can, return the number, else return 0
int get(int a[], int i){
	int ans = 0;
	for(int j=31; j>=0; j--){
		ans = (ans<<1)|fetch(a, i, j);
	}
	return ans;
}

int findMissing(int a[], int n){
	bool *b = new bool[n+1];
	memset(b, false, (n+1)*sizeof(bool));
	for(int i=0; i<n; i++){
		b[get(a, i)] = true;
	}
	for(int i=0; i<n+1; i++){
		if(!b[i]){
			return i;
		}
	}
}

int main(){
	int a[] = {0, 1, 2, 3, 4, 5, 7, 8, 9, 10};
	cout<<findMissing(a, 10)<<endl;
	return 0;
}