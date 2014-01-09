#include <iostream>
#include <vector>
#include <string>
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

int main(){
	string src = "abcd";
	vector<string> result = getPerms(src);
	for(int i=0; i<result.size(); i++){
		cout<<result[i]<<endl;
	}
	return 0;
}