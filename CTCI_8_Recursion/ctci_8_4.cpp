#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// get the 1st char of the string, like 'a' of 'abcd', then put 'a' to the other place of the remain string, from 'abcd' to 'bcda', and keep it
vector<string> getPerms(string src){
	vector<string> result;
	if(src == ""){
		result.push_back("");
		return result;
	}
	// get the start char
	string start = src.substr(0, 1);
	vector<string> remain = getPerms(src.substr(1));
	for(int i=0; i<remain.size(); i++){
		string tmp = remain[i];
		for(int j=0; j<=tmp.length(); j++){
			string unit = tmp;
			unit.insert(j, start);
			result.push_back(unit);
		}
	}
	return result;
}

// similar to leetcode permutation, this is string, leetcode is vector<int>
void dfsPermute(string src, int level, vector<bool> &visited, string sub, vector<string> &res) {
	if(sub.size() == src.size()) {
		res.push_back(sub);
		return;
	}
	for(int i = 0; i < src.size(); i++) {
		if(visited[i] == false) {
			visited[i] = true;
			sub.push_back(src[i]);
			dfsPermute(src, i+1, visited, sub, res);
			visited[i] = false;
			sub.resize(sub.size() - 1);
		}
	}
}

vector<string> permute(string src) {
	vector<string> res;
	if(src.size() == 0) {
		return res;
	}
	sort(src.begin(), src.end());
	string sub = "";
	vector<bool> visited(src.size(), false);
	dfsPermute(src, 0, visited, sub, res);
	return res;
}

int main(){
	string src = "abcd";
	vector<string> result1 = getPerms(src);
	vector<string> result2 = permute(src);
	for(int i=0; i<result1.size(); i++){
		cout<<result1[i]<<endl;
	}
	cout<<endl;
	for(int i=0; i<result2.size(); i++){
		cout<<result2[i]<<endl;
	}
	return 0;
}