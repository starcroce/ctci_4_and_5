#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

// also the 1_3 of version 5
// running time O(nlogn), space O(1)
bool isAnagram(string s1, string s2){
	int len1 = s1.length();
	int len2 = s2.length();
	if(len1 != len2)
		return false;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	return (s1 == s2);
}

// running time O(n), space O(1)
bool isAnagram2(string s1, string s2)
{
	vector<int> charCount(256, 0);
	for(int i = 0; i < s1.size(); i++)
		charCount[s1[i]]++;
	for(int i = 0; i < s2.size(); i++)
		charCount[s2[i]]--;
	for(int i = 0; i < 256; i++)
	{
		if(charCount[i] != 0)
			return false;
	}
	return true;
}

int main(){
	string s1 = "aabb";
	string s2 = "abab";
	string s3 = "aaab";
	cout<<isAnagram(s1, s2)<<" "<<isAnagram(s1, s3)<<endl;
	cout<<isAnagram2(s1, s2)<<" "<<isAnagram2(s1, s3)<<endl;
	return 0;
}