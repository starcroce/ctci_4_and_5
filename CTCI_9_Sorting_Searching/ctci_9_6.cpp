#include <iostream>
using namespace std;

int matrix[5][5] = {
	{1, 2, 3, 4, 5},
	{6, 7, 8, 9, 10},
	{11, 12, 13, 14, 15},
	{16, 17, 18, 19, 20},
	{21, 22, 23, 24, 25},
};

int findElem(int m, int n, int x){
	// should start from top right, then move left is decreasing, move down is increasing
	int row = 0, col = n-1;
	while(row < m && col >= 0){
		if(matrix[row][col] == x)
			return (row*n+col);
		else if(matrix[row][col] > x)
			col--;
		else
			row++;
	}
	return -1;
}

int main(){
	int pos = findElem(5, 5, 13);
	cout<<"Pos: "<<pos/5<<", "<<pos%5<<endl;
	return 0;
}