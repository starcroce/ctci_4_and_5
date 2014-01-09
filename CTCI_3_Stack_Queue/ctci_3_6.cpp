#include <iostream>
#include <cstdlib>
#include <stack>
#include <queue>
#include <ctime>
using namespace std;

void qSort(stack<int> &s){
	priority_queue<int, vector<int>, greater<int> > q;
	while(!s.empty()){
		q.push(s.top());
		s.pop();
	}
	while(!q.empty()){
		s.push(q.top());
		q.pop();
	}
}

// O(n^2) time and O(n) space
stack<int> sSort(stack<int> s){
	stack<int> t;
	while(!s.empty()){
		int data = s.top();
		s.pop();
		while(!t.empty() && t.top()>data){
			s.push(t.top());
			t.pop();
		}
		t.push(data);
	}
	return t;
}

int main(){
	srand((unsigned)time(0));
	stack<int> s;
	for(int i=0; i<10; i++){
		s.push((rand()%100));
	}
	s = sSort(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	for(int i=0; i<10; i++){
		s.push((rand()%100));
	}
	qSort(s);
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();
	}
	cout<<endl;
	return 0;
}