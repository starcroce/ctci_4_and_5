#include <iostream>
#include <stack>
using namespace std;

template <typename T>
class MyQueue{
public:
	MyQueue();
	~MyQueue();
	void push(T data){
		move(sOut, sIn);
		sIn.push(data);
	}
	void pop(){
		move(sIn, sOut);
		sOut.pop();
	}
	void move(stack<T> &src, stack<T> &dst){
		while(!src.empty()){
			dst.push(src.top());
			src.pop();
		}
	}
	T front(){
		move(sIn, sOut);
		return sOut.top();
	}
	T rear(){
		move(sOut, sIn);
		return sIn.top();
	}
private:
	// sOut is for pop and front
	// sIn is for push and rear
	stack<T> sIn, sOut;
};

int main(){
	MyQueue<int> q;
	for(int i=0; i<10; i++){
		q.push(i);
	}
	cout<<q.front()<<" "<<q.rear()<<endl;
	q.pop();
	cout<<q.front()<<" "<<q.rear()<<endl;
	q.push(11);
	cout<<q.front()<<" "<<q.rear()<<endl;
	return 0;
}