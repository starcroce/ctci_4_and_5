#include <iostream>
#include <cstring>
using namespace std;

class Trie{
public:
	static const int maxNum = 100*100; // assume the length of main string is 100
	static const int charNum = 26;
	int size;
	int trie[maxNum][charNum];
	Trie(const char *s);
	void insert(const char *s);
	bool find(const char *s);
};

Trie::Trie(const char *s){
	// set the first num of the block of memory pointed by ptr to specified value
	memset(trie[0], -1, sizeof(trie[0]));
	size = 1;
	while(*s){
		insert(s);
		s++;
	}
}

void Trie::insert(const char *s){
	int p = 0;
	while(*s){
		int i = *s-'a';
		if(trie[p][i] == -1){
			memset(trie[size], -1, sizeof(trie[size]));
			trie[p][i] = size++;
		}
		p = trie[p][i];
		s++;
	}
}

bool Trie::find(const char *s){
	int p = 0;
	while(*s){
		int i = *s-'a';
		if(trie[p][i] == -1)
			return false;
		p = trie[p][i];
		s++;
	}
	return true;
}

int main(){
	Trie tree("mississippi");
	string pattern[] = {
		"is", "sip", "hi", "sis", "mississippa",
	};
	int n = 5;
	for(int i=0; i<5; i++){
		cout<<tree.find((char*)&pattern[i][0])<<endl;
	}
	return 0;
}