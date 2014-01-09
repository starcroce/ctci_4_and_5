#include <iostream>
using namespace std;

enum Check{
	ROW, COLUMN, DIAGONAL, REDIAGONAL
};

int checkRowColumn(int board[], int n, Check check){
	int type = 0;
	for(int i=0; i<n; i++){
		bool found = true;
		for(int j=0; j<n; j++){
			int k = 0;
			if(check == ROW)
				k = i*n+j; // position of the board
			else
				k = i+j*n;
			// check if the same row or column has all the same type
			if(j == 0)
				type = board[k];
			else if(board[k] != type){
				found = false; // if not win, break
				break;
			}
		}
		if(found)
			return type;
	}
	return 0;
}

int checkDiagonal(int board[], int n, Check check){
	int type = 0;
	bool found = true;
	for(int i=0; i<n; i++){
		int k = 0;
		if(check == DIAGONAL)
			k = i+i*n;
		else
			k = i+(n-1-i)*n;
		if(i == 0)
			type = board[k];
		else if(board[k] != type){
			found = false;
			break;
		}
	}
	if(found)
		return type;
	return 0;
}

int hasWon(int board[], int n){
	int type = 0;
	type = checkRowColumn(board, n, ROW);
	if(type != 0)
		return type;
	type = checkRowColumn(board, n, COLUMN);
	if(type != 0)
		return type;
	type = checkDiagonal(board, n, DIAGONAL);
	if(type != 0)
		return type;
	type = checkDiagonal(board, n, REDIAGONAL);
	if(type != 0)
		return type;
	return 0;
}

int main(){
	int n = 3;
	int board[] = {
		2, 2, 2, 
		2, 1, 1, 
		1, 2, 0
	};
	int type = hasWon(board, n);
	if(type != 0)
		cout<<type<<" won!"<<endl;
	else
		cout<<"nobody won!"<<endl;
	return 0;
}