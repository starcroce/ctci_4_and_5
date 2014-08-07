#include <iostream>
#include <vector>
#include <string>
using namespace std;

void putQueens(int row, int n, vector<vector<char> > &board, vector<vector<string> > &res) {
	if(row == n) {
		vector<string> sol;
		for(int i = 0; i < n; i++) {
			sol.push_back(string(board[i].begin(), board[i].end()));
		}
		res.push_back(sol);
		return;
	}
	for(int i = 0; i < n; i++) {
		bool canPlaceQueen = true;
		for(int j = 0; j < row; j++) {
			if(board[j][i] == 'Q') {
				canPlaceQueen = false;
				break;
			}
		}
		for(int j = row-1, k = i+1; k < n && j >= 0; k++, j--) {
			if(board[j][k] == 'Q') {
				canPlaceQueen = false;
				break;
			}
		}
		for(int j = row-1, k = i-1; k >= 0 && j >= 0; k--, j--) {
			if(board[j][k] == 'Q') {
				canPlaceQueen = false;
				break;
			}
		}
		if(canPlaceQueen == false) {
			continue;
		}
		board[row][i] = 'Q';
		putQueens(row+1, n, board, res);
		board[row][i] = '.';
	}
}

vector<vector<string> > nQueens(int n) {
	vector<vector<string> > res;
	vector<vector<char> > board(n, vector<char> (n, '.'));
	int row = 0;
	putQueens(row, n, board, res);
	return res;
}

int main(int argc, char const *argv[])
{
	vector<vector<string> > res = nQueens(4);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout<<res[i][j]<<endl;
		}
		cout<<endl;
	}
	return 0;
}