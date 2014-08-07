#include <iostream>
using namespace std;

class stack3
{
public:
	stack3(int size = 300)
	{
		buff = new int[size*3];
		// stackTop[] is the offset of the index from size * stackNum
		stackTop[0] = stackTop[1] = stackTop[2] = -1;
		this->size = size;
	}
	~stack3()
	{
		delete[] buff;
	}
	void push(int stackNum, int data)
	{
		// update the new index
		int index = stackNum*size+stackTop[stackNum]+1;
		buff[index] = data;
		stackTop[stackNum]++;
	}
	void pop(int stackNum)
	{
		stackTop[stackNum]--;
	}
	int top(int stackNum)
	{
		int index = stackNum*size+stackTop[stackNum];
		return buff[index];
	}

private:
	int *buff;
	int stackTop[3];
	int size;
};

int main(int argc, char const *argv[])
{
	stack3 myStack;
	for(int i = 0; i < 10; i++)
	{
		myStack.push(0, i);
	}
	for(int i = 20; i < 30; i++)
	{
		myStack.push(1, i);
	}
	for(int i = 100; i < 120; i++)
	{
		myStack.push(2, i);
	}
	for(int i = 0; i < 3; i++)
	{
		cout<<myStack.top(i)<<" ";
	}
	cout<<endl;
	for(int i=0; i<3; i++)
	{
		myStack.pop(i);
		cout<<myStack.top(i)<<" ";
	}
	cout<<endl;
	return 0;
}