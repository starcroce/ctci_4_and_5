#include <iostream>
#include <string>
using namespace std;

int search(string s[], int low, int high, string x){
	if(x == "")
		return -1;
	while(low <= high){
		int mid = (low+high)/2;
		int tmp = mid;
		// check the elements after mid are whether all ""
		while(s[tmp] == "" && tmp <= high){
			tmp++;
		}
		if(tmp > high) // it means that after mid there are all ""
			high = mid-1;
		else{
			if(s[tmp] == x)
				return tmp;
			else if(s[tmp] < x)
				low = tmp+1;
			else
				high = mid-1;
		}
	}
	return -1;
}

int main(){
	string s[13] = {
		"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
	};
	cout<<search(s, 0, 12, "ball")<<endl;
	return 0;
}