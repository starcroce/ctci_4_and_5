#include <iostream>
#include <algorithm>
#include <string>
#include "ctci_20_7.h"
using namespace std;

Hash hash;

inline bool cmp(string s1, string s2){
	return s2.length() < s1.length();
}

bool makeOfWords(string word, int length){
	int len = word.length();
	// cout<<len<<endl;
	if(len == 0)
		return true;
	for(int i=1; i<=len; i++){
		// get the string itself, so return false
		if(i == length)
			return false;
		string str = word.substr(0, i);
		// cout<<str<<endl;
		if(hash.find((char*)&str[0])){
			if(makeOfWords(word.substr(i), length))
				return true;
		}
	}
	return false;
}

void printLongestWord(string word[], int n){
	for(int i=0; i<n; i++){
		hash.insert((char*)&word[i][0]);
	}
	sort(word, word+n, cmp);
	for(int i=0; i<n; i++){
		if(makeOfWords(word[i], word[i].length())){
			cout<<word[i]<<endl;
			return;
		}
	}
}

int main(){
	string words[] = {
		"test", "tester", "testertest", "testing", "apple", "seattle", "banana",  "batting", "ngcat", "batti","bat", "testingtester", "testbattingcat"
	};
	int len = 13;
	printLongestWord(words, len);
	return 0;
}