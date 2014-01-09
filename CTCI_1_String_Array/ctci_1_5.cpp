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
	int newlen = len+spaceCount*2;
	s[newlen] = '\0';
	int k = newlen;
	k--;
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