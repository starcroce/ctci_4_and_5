#include <iostream>
#include <climits>
using namespace std;

const int INIT = INT_MAX;

// use a struct to store the min value
// can easily add max value
typedef struct node
{
	int data;
	int min;
} node;

class stackWithMin
{
public:
	stackWithMin(int size = 100)
	{
		buff = new node[size];
		buff[0].min = INIT;
		index = 0;
	}
	~stackWithMin()
	{
		delete[] buff;
	}
	void push(int data)
	{
		index++;
		buff[index].data = data;
		// update the min value when push
		if(data < buff[index-1].min)
			buff[index].min = data;
		else
			buff[index].min = buff[index-1].min;
	}
	void pop()
	{
		index--;
	}
	int top()
	{
		return buff[index].data;
	}
	int min()
	{
		return buff[index].min;
	}

private:
	node *buff;
	int index;
};

int main(int argc, char const *argv[])
{
	stackWithMin myStack;
	for(int i = 20; i > 0; i--){
		myStack.push(i);
	}
	cout<<myStack.min()<<" "<<myStack.top()<<endl;
	myStack.pop();
	cout<<myStack.min()<<" "<<myStack.top()<<endl;
	return 0;
}