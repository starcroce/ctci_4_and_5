#include <iostream>
#include <cstring>
using namespace std;

void removeDuplicate(char *s){
	int len = strlen(s);
	if(len < 2)
		return;
	bool a[256];
	for(int i=0; i<256; i++){
		a[i] = true;
	}
	int k = 0;
	for(int i=0; i<len; i++){
		if(a[s[i]]){
			s[k] = s[i];
			k++;
			a[s[i]] = false;
		}
	}
	s[k] = '\0';
}

int main(){
	char s1[] = "qwerty";
	char s2[] = "qqqqqq";
	char s3[] = "";
	char s4[] = "qweqwt";
	removeDuplicate(s1);
	removeDuplicate(s2);
	removeDuplicate(s3);
	removeDuplicate(s4);
	cout<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
	return 0;
}