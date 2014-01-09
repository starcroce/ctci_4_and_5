#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int getNum(int k){
	if(k <= 0)
		return 0;
	int val = 1, count = 1;
	queue<int> q3, q5, q7;
	q3.push(3);
	q5.push(5);
	q7.push(7);
	for(; count<k; count++){
		int v3 = q3.front();
		int v5 = q5.front();
		int v7 = q7.front();
		// initialize q3, q5 and q7
		// push 1 into num
		// push 1*3, 1*5 and 1*7 into queues
		// let x be the min num in q3, q5 and q7
		// if x was found in
		// push 3x, 5x and 7x to q3, q5 and q7, pop x from q3
		// push 5x and 7x into q5 and q7, pop x from q5
		// push 7x into q7, pop x from q7
		val = min(min(v3, v5), v7);
		if(val == v7)
			q7.pop();
		else{
			if(val == v5)
				q5.pop();
			else{
				q3.pop();
				q3.push(val*3);
			}
			q5.push(val*5);
		}
		q7.push(val*7);
	}
	return val;
}

int main(){
	for(int i=1; i<=20; i++){
		cout<<getNum(i)<<" ";
	}
	cout<<endl;
	return 0;
}