#include <iostream>
#include <vector>
using namespace std;

void getCoins(int A[], int n, int target, int sum, int num, vector<int> &sol, vector<vector<int> > &res) {
	if(sum > target) {
		return;
	} else if(sum == target) {
		res.push_back(sol);
		return;
	}
	for(int i = num; i < n; i++) {
		sum += A[i];
		sol.push_back(A[i]);
		getCoins(A, n, target, sum, i, sol, res);
		sol.pop_back();
		sum -= A[i];
	}
}

vector<vector<int> > coinSum(int A[], int n, int target) {
	vector<vector<int> > res;
	vector<int> sol;
	int sum = 0, num = 0;
	getCoins(A, n, target, sum, num, sol, res);
	return res;
}

int main(int argc, char const *argv[])
{
	int A[] = {1, 5, 10, 25};
	vector<vector<int> > res = coinSum(A, 4, 30);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}