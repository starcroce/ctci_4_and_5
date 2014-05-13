#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix_clock(vector<vector<int> > &m)
{
	int len = m.size();
	for(int i = 0; i < len / 2; i++)
	{
		int start = i, end = len - 1 - i;
		for(int j = start; j < end; j++)
		{
			int offset = j - start;
			int top = m[start][j];
			m[start][j] = m[end-offset][start];
			m[end-offset][start] = m[end][end-offset];
			m[end][end-offset] = m[j][end];
			m[j][end] = top;
		}
	}
}

void rotateMatrix_counterclock(vector<vector<int> > &m)
{
	int len = m.size();
	for(int i = 0; i < len / 2; i++)
	{
		int start = i, end = len - 1 - i;
		for(int j = start; j < end; j++)
		{
			int offset = j - start;
			int top = m[start][j];
			m[start][j] = m[j][end];
			m[j][end] = m[end][end-offset];
			m[end][end-offset] = m[end-offset][start];
			m[end-offset][start] = top;
		}
	}
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > table(4, vector<int> (4));
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			table[i][j] = i + j;
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	rotateMatrix_clock(table);
	cout<<endl;
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	rotateMatrix_counterclock(table);
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}