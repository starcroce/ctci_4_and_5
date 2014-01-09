#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool isAnagram(string s1, string s2){
	int len1 = s1.length();
	int len2 = s2.length();
	if(len1 != len2)
		return false;
	sort(&s1[0], &s1[0]+len1);
	sort(&s2[0], &s2[0]+len2);
	return (s1 == s2);
}

int main(){
	string s1 = "aabb";
	string s2 = "abab";
	string s3 = "aaab";
	cout<<isAnagram(s1, s2)<<" "<<isAnagram(s1, s3)<<endl;
	return 0;
}