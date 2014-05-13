#include <iostream>
#include <cstring>
using namespace std;

void replace(char *s)
{
	int spaceCount = 0, len = strlen(s);
	for(int i = 0; i < strlen(s); i++)
		if(s[i] == ' ')
			spaceCount++;
	int newLen = len + spaceCount * 2;
	s[newLen] = '\0';
	int k = newLen - 1;
	for(int i = len-1; i >= 0; i--)
	{
		if(s[i] == ' ')
		{
			s[k] = '0'; s[k-1] = '2'; s[k-2] = '%';
			k -= 3;
		}
		else
		{
			s[k] = s[i];
			k--;
		}
	}
}

int main(int argc, char const *argv[])
{
	char s[] = "i have a dream";
	replace(s);
	cout<<s<<endl;
	return 0;
}