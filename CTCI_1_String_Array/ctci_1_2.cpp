#include <iostream>
#include <cstring>
using namespace std;

void swap(char &a, char &b){
	char t = a;
	a = b;
	b = t;
}

// remeber Microsoft!!!
void reverseString(char *s){
	int len = strlen(s);
	// the length of the loop is len/2
	// the sum of the index is len-1
	for(int i=0; i<len/2; i++){
		swap(s[i], s[len-i-1]);
	}
}

int main(){
	char s[] = "qwertyiop";
	reverseString(s);
	cout<<s<<endl;
	return 0;
