#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateMatrix_clock(vector<vector<int> > &m)
{
	int len = m.size();
	for(int i = 0; i < len / 2; i++)
	{
		// end is the next to the last position
		int start = i, end = len - 1 - i;
		for(int j = start; j < end; j++)
		{
			int offset = j - start;
			// save top
			int top = m[start][j];
			// top is left
			m[start][j] = m[end-offset][start];
			// left is bottom
			m[end-offset][start] = m[end][end-offset];
			// bottom is right
			m[end][end-offset] = m[j][end];
			// right is top
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

// see the python file for more details about the algo
// counterclock: topleft - bottomright
void rotateMatrix_counterclock_simple(vector<vector<int> > &m)
{
	int len = m.size();
	for(int i = 0; i < len; i++)
	{
		for(int j = i+1; j < len; j++)
		{
			int tmp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = tmp;
		}
	}
	reverse(m.begin(),m.end());
}

// clock: topright - bottomleft
void rotateMatrix_clock_simple(vector<vector<int> > &m)
{
	int len = m.size();
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len-i; j++)
		{
			int tmp = m[i][j];
			m[i][j] = m[len-1-j][len-1-i];
			m[len-1-j][len-1-i] = tmp;
		}
	}
	reverse(m.begin(), m.end());
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
	rotateMatrix_clock_simple(table);
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
	rotateMatrix_counterclock_simple(table);
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