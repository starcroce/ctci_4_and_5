#include <iostream>
using namespace std;

const int INIT = ~(1<<31);

// use a struct to store the min value
// can easily add max value
typedef struct node{
	int data, min;
}node;

class stackWithMin{
public:
	stackWithMin(int size = 100){
		buff = new node[size];
		buff[0].min = INIT;
		index = 0;
	}
	~stackWithMin(){
		delete[] buff;
	}
	void push(int data){
		index++;
		buff[index].data = data;
		// update the min value when push
		if(data < buff[index-1].min)
			buff[index].min = data;
		else
			buff[index].min = buff[index-1].min;
	}
	void pop(){
		index--;
	}
	int top(){
		return buff[index].data;
	}
	int min(){
		return buff[index].min;
	}
private:
	node *buff;
	int index;
};

int main(){
	stackWithMin myStack;
	for(int i=0; i<20; i++){
		myStack.push(i);
	}
	cout<<myStack.min()<<endl;
}