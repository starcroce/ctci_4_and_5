#include <iostream>
using namespace std;

#define BIG_ENDIAN 0
#define LITTLE_ENDIAN 1

int main(){
	int word = 0x0001;
	char *byte = (char *) &word;
	if(byte[0])
		cout<<BIG_ENDIAN<<endl;
	else
		cout<<LITTLE_ENDIAN<<endl;
	return 0;
}