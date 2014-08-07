#include <iostream>
#include <stack>
#include <vector>
using namespace std;

const int STACK_SIZE = 100;
const int STACK_NUM = 10;

bool stackIsFull(stack<int> &s)
{
	return s.size() > STACK_SIZE;
}

void setOfStackPush(vector<stack<int> > &sos, int val)
{
	for(int i = 0; i < STACK_NUM; i++)
	{
		if(stackIsFull(sos[i]) == false)
		{
			sos[i].push(val);
			return;
		}
	}
}

int top(vector<stack<int> > &sos)
{
	for(int i = STACK_NUM-1; i >= 0; i--)
	{
		if(sos[i].empty() == false)
			return sos[i].top();
	}
}

void pop(vector<stack<int> > &sos)
{
	for(int i = STACK_NUM-1; i >= 0; i--)
	{
		if(sos[i].empty() == false)
		{
			sos[i].pop();
			return;
		}
	}
}

void popAt(vector<stack<int> > &sos, int index)
{
	if(sos[index].empty() == false)
	{
		sos[index].pop();
	}
	else
	{
		cout<<"current stack is empty"<<endl;
	}
}

int main(int argc, char const *argv[])
{
	vector<stack<int> > sos(STACK_NUM, stack<int> ());
	for(int i = 0; i < 350; i++)
	{
		setOfStackPush(sos, i);
	}
	cout<<top(sos)<<endl;
	popAt(sos, 1);
	popAt(sos, 8);
	return 0;
}