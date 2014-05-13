#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isUnique(string s)
{
	vector<bool> table(256, false);
	for(int i = 0; i < s.size(); i++)
	{
		int pos = (int)s[i];
		if(table[pos] == true)
			return false;
		table[pos] = true;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string s1 = "i have a dream";
	string s2 = "qwertyuiop";
	cout<<isUnique(s1)<<" "<<isUnique(s2)<<endl;
	return 0;
}