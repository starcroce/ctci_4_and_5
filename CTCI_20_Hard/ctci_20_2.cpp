#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void shuffleCards(int card[], int length){
	int tmp, index;
	for(int i=0; i<length; i++){
		double randNum = ((double)rand())/RAND_MAX;
		// get a random num from the array
		index = (int)(randNum*(length-i))+i;
		// swap it with the first element in the array so it would not be selected in the future
		tmp = card[i];
		card[i] = card[index];
		card[index] = tmp;
	}
}

int main(){
	srand((unsigned)time(NULL));
	int card[52];
	for(int i=0; i<52; i++){
		card[i] = i;
	}
	shuffleCards(card, 52);
	for(int i=0; i<52; i++){
		cout<<card[i]<<" ";
	}
	cout<<endl;
	return 0;
}