// same as leetcode n-queens
// for each row, check the col and diagonal, then recursively process the next row
#include <iostream>
using namespace std;

// 8 positions in a row make c[]
int c[8], n = 8, count = 0;

void printBoard(){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j == c[i])
				cout<<"1 ";
			else
				cout<<"0 ";
		}
		cout<<endl;
	}
	cout<<endl;
}

// place queen in the rth row
void placeQueen(int r){
	if(r == n){
		printBoard();
		count++;
		return;
	}
	for(int i=0; i<n; i++){
		c[r] = i;
		bool flag = true;
		for(int j=0; j<r; j++){
			// if the queens are on the same column or diagonal, then break
			if(c[r] == c[j] || c[r]-c[j] == r-j || c[r]-c[j] == j-r){
				flag = false;
				break;
			}
		}
		if(flag)
			placeQueen(r+1);
	}
}

int main(){
	placeQueen(0);
	cout<<count<<endl;
	return 0;
}