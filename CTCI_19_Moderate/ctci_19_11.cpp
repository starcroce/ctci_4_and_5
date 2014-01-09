#include <iostream>
#include <algorithm>
using namespace std;

void printPairSums(int array[], int sum, int length){
	sort(array, array+length);
	int first = 0, last = length-1;
	while(first < last){
		int s = array[first]+array[last];
		if(s == sum){
			cout<<array[first]<<" "<<array[last]<<endl;
			first++;
			last--;
		}
		else{
			if(s < sum)
				first++;
			else
				last--;
		}
	}
}

int main(){
	int array[] = {-2, 0, -1, 5, 3, 6, 7, 9, 14, 13};
	int sum = 12;
	int length = sizeof(array)/sizeof(array[0]);
	printPairSums(array, sum, length);
	return 0;
}