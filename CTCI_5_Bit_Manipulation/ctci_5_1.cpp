#include <iostream>
#include <vector>
using namespace std;

int updateBits(int n, int m, int i, int j){
	int max = ~0;
	int left = max-((1<<j)-1);
	int right = ((1<<i)-1);
	int mask = left|right;
	return (n&mask)|(m<<i);
}

void printBinary(int n){
	vector<int> v;
	while(n != 0){
		if(n&1){
			v.push_back(1);
		}
		else{
			v.push_back(0);
		}
		n >>= 1;
	}
	while(!v.empty()){
		cout<<v.back();
		v.pop_back();
	}
	cout<<endl;
}

int main(){
	int n = 1<<10, m = 21;
	int ans = updateBits(n, m, 2, 6);
	printBinary(n);
	printBinary(m);
	printBinary(ans);
	return 0;
}