#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void pickMRandomly(int a[], int n, int m){
	int tmp;
	for(int i=0; i<m; i++){
		int j = rand()%(n-i)+i; // get a random num from i to n-1
		// swap the selected with the ith in order to avoid select it again
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}
}

int main(){
	srand((unsigned)time(NULL));
	int n = 9, m = 5;
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	pickMRandomly(a, n, m);
	for(int i=0; i<m; i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}