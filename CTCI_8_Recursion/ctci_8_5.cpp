#include <iostream>
using namespace std;

// as long as we haven't used up all the left parentheses, we can always insert a left paren
// we can always insert a right paren if there are more right parens remaining than left
void printPair(int left, int right, char str[], int count){
	if(left < 0 || right < left)
		return;
	if(left == 0 && right == 0){
		for(int i=0; i<count; i++){
			cout<<str[i];
		}
		cout<<", ";
	}
	else{
		if(left > 0){
			str[count] = '(';
			printPair(left-1, right, str, count+1);
		}
		if(right > left){
			str[count] = ')';
			printPair(left, right-1, str, count+1);
		}
	}
}

// some small bug like i cannot remove the last ','
int main(){
	int count = 3;
	char str[count*2];
	printPair(count, count, str, 0);
	return 0;
}