#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getPairs(int left, int right, string sol, vector<string> &res) {
	if(left == 0 && right == 0) {
		res.push_back(sol);
		return;
	}
	if(left > 0) {
		getPairs(left-1, right, sol+'(', res);
	}
	if(right > left) {
		getPairs(left, right-1, sol+')', res);
	}
}

vector<string> allValidParentheses(int n) {
	vector<string> res;
	int left = n, right = n;
	string sol;
	getPairs(left, right, sol, res);
	return res;
}

int main(int argc, char const *argv[])
{
	int n = 3;
	vector<string> res = allValidParentheses(n);
	for(int i = 0; i < res.size(); i++) {
		cout<<res[i]<<endl;
	}
	return 0;
}