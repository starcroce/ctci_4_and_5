#include <iostream>
using namespace std;

const int STACK_SIZE = 100;

class stack{
public:
	stack(int size = STACK_SIZE){
		buff = new int[size];
		index = -1;
		size = size;
	}
	~stack(){
		delete[] buff;
	}
	void push(int data){
		index++;
		buff[index] = data;
	}
	void pop(){
		index--;
	}
	int top(){
		return buff[index];
	}
	bool isFull(){
		return index == size-1;
	}
	bool isEmpty(){
		return index == -1;
	}
private:
	int *buff;
	int index;
	int size;
};

class setOfStacks{
public:
	setOfStacks(int size = STACK_SIZE){
		st = new stack[size];
		index = 0;
		size = size;
	}
	~setOfStacks(){
		delete[] st;
	}
	void push(int data){
		if(st[index].isFull())
			index++;
		st[index].push(data);
	}
	void pop(){
		while(st[index].isEmpty()){
			index--;
		}
		st[index].pop();
	}
	void popAt(int index){
		while(st[index].isEmpty()){
			index--;
		}
		st[index].pop();
	}
	int top(){
		while(st[index].isEmpty()){
			index--;
		}
		return st[index].top();
	}
private:
	stack *st;
	int index;
	int size;
};

int main(){
	setOfStacks ss;
	for(int i=0; i<3*STACK_SIZE+1; i++){
		ss.push(i);
	}
	for(int i=0; i<STACK_SIZE; i++){
		ss.popAt(0);
		ss.popAt(2);
	}
	cout<<ss.top()<<endl;
	return 0;
}