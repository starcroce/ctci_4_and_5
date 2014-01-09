#include <iostream>
using namespace std;

int count2InOneNum(int n){
	int count = 0;
	while(n > 0){
		if(n%10 == 2)
			count++;
		n /= 10;
	}
	return count;
}

int count2(int n){
	int count = 0;
	for(int i=0; i<=n; i++){
		count += count2InOneNum(i);
	}
	return count;
}

int main(){
	cout<<count2(200)<<endl;
	return 0;
}