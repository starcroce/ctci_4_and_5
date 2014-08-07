#include <iostream>
#include <vector>
using namespace std;

void getSubsets(int A[], int len, int num, vector<int> &sol, vector<vector<int> > &res) {
	res.push_back(sol);
	for(int i = num; i < len; i++) {
		sol.push_back(A[i]);
		getSubsets(A, len, i+1, sol, res);
		sol.pop_back();
	}
}

vector<vector<int> > subsets(int A[], int len) {
	vector<vector<int> > res;
	vector<int> sol;
	int num = 0;
	getSubsets(A, len, num, sol, res);
	return res;
}

int main(int argc, char const *argv[])
{
	int A[] = {1, 2, 3, 4};
	vector<vector<int> > res = subsets(A, 4);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout<<res[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}