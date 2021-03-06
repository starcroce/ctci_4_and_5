#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
// write a method to sort an array of strings so that all the anagrams are next to each other

bool stringCompare(string s1, string s2){
	sort(&s1[0], &s1[0]+s1.length());
	sort(&s2[0], &s2[0]+s2.length());
	// str1 < str2 only compare the char, it doesn't care about the length
	return s1 < s2;
}

int main(){
	string s[] = {
		"axyz", "abc", "yzax", "bac", "zyxa", "fg", "gf"
	};
	sort(s, s+7, stringCompare);
	for(int i=0; i<7; i++){
		cout<<s[i]<<endl;
	}
	return 0;
}