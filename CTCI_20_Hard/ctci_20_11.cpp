#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

// iterate through every col from left to right, for each col look at the biggest subcol, and for each subcol, check if can form a square
// break when n-current_col <= current_max_size

int matrix[100][100]; // the max size of matrix

struct subSquare{
	int row, col, size;
};

// 1 is white and 0 is black
bool isSquare(int row, int col, int size){
	for(int i=0; i<size; i++){
		if(matrix[row][col+i] == 1)
			return false;
		if(matrix[row+size-1][col+i] == 1)
			return false;
		if(matrix[row+i][col] == 1)
			return false;
		if(matrix[row+i][col+size-1] == 1)
			return false;
	}
	return true;
}

subSquare findSubSquare(int n){
	int maxSize = 0;
	int col = 0;
	subSquare sq;
	while(n-col > maxSize){
		for(int row=0; row<n; row++){
			int size = n-max(row, col);
			while(size > maxSize){
				if(isSquare(row, col, size)){
					maxSize = size;
					sq.row = row;
					sq.col = col;
					sq.size = size;
					break;
				}
				size--;
			}
		}
		col++;
	}
	return sq;
}

int main(){
	freopen("20_11.in", "r", stdin);
	int n = 8; // size of the input matrix
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>matrix[i][j];
		}
	}
	subSquare sq = findSubSquare(n);
	cout<<"top: "<<sq.row<<endl;
	cout<<"bottom: "<<sq.row+sq.size-1<<endl;
	cout<<"left: "<<sq.col<<endl;
	cout<<"right: "<<sq.col+sq.size-1<<endl;
	fclose(stdin);\
	return 0;
}