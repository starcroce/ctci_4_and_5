#include <iostream>
#include <cstring>
using namespace std;

void replace(char *s){
	int len = strlen(s);
	if(len == 0)
		return;
	int spaceCount = 0;
	for(int i=0; i<len; i++){
		if(s[i] == ' ')
			spaceCount++;
	}
	// convert ' ' to "%20", add 2 char every time
	int newlen = len+spaceCount*2;
	s[newlen] = '\0';
	// k is the last index of the result
	int k = newlen - 1;
	// k--;
	for(int i=len-1; i>=0; i--){
		if(s[i] == ' '){
			s[k] = '0';
			s[k-1] = '2';
			s[k-2] = '%';
			k -= 3;
		}
		else{
			s[k] = s[i];
			k--;
		}
	}
}

int main(){
	char s[] = "i have a dream";
	replace(s);
	cout<<s<<endl;
	return 0;
}