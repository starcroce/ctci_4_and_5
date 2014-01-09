#include <iostream>
#include <string>
using namespace std;

const int MAX = ~(1<<31); // the max int value

int shortest(string words[], string word1, string word2, int length){
	// no idea why set the following 3 int?
	int min = MAX/2;
	int pos1 = -min, pos2 = -min;
	int dist;
	for(int pos=0; pos<length; pos++){
		if(words[pos] == word1){
			pos1 = pos;
			// comment the following 3 lines if word order matter
			dist = pos1-pos2;
			if(dist < min)
				min = dist;
		}
		else if(words[pos] == word2){
			pos2 = pos;
			dist = pos2-pos1;
			if(dist < min)
				min = dist;
		}
	}
	return min;
}

int main(){
	string words[] = {
		"what", "is", "your", "name", "my", "name", "is", "starcroce"
	};
	int length = sizeof(words)/sizeof(words[0]);
	cout<<shortest(words, "is", "name", length)<<endl;
	return 0;
}