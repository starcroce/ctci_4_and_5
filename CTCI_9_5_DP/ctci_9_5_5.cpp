#include <iostream>
#include <vector>
using namespace std;

void getPermutation(string s, int num, vector<bool> &visited, vector<char> &sol, vector<vector<char> > &res) {
	if(sol.size() == s.size()) {
		res.push_back(sol);
		return;
	}
	for(int i = 0; i < s.size(); i++) {
		if(visited[i] == false) {
			visited[i] = true;
			sol.push_back(s[i]);
			getPermutation(s, i+1, visited, sol, res);
			sol.pop_back();
			visited[i] = false;
		}
	}
}

vector<vector<char> > permutations(string s) {
	vector<vector<char> > res;
	vector<char> sol;
	int num = 0;
	vector<bool> visited(s.size(), false);
	getPermutation(s, num, visited, sol, res);
	return res;
}

int main(int argc, char const *argv[])
{
	string s = "abcd";
	vector<vector<char> > res = permutations(s);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout<<res[i][j];
		}
		cout<<endl;
	}
	return 0;
}