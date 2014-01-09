#include <iostream>
#include <string>
using namespace std;

bool isUnique(string s){
	bool a[256];
	for(int i=0; i<256; i++){
		a[i] = false;
	}
	int len = s.length();
	for(int i=0; i<len; i++){
		int n = (int)s[i];
		if(a[n])
			return false;
		a[n] = true;
	}
	return true;
}

int main(){
	string s1 = "i have a dream";
	string s2 = "qwertyuiop";
	cout<<isUnique(s1)<<" "<<isUnique(s2)<<endl;
	return 0;
}