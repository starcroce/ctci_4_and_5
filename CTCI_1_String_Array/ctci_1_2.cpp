#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char *s)
{
	int start = 0, end = strlen(s) - 1;
	while(start < end)
	{
		char tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		start++; end--;
	}

}

int main(int argc, char const *argv[])
{
	char s[] = "qwertyiop";
	reverseString(s);
	cout<<s<<endl;
	return 0;
}