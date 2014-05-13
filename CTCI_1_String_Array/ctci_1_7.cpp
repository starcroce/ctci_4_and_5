#include <iostream>
#include <vector>
using namespace std;

void setZero(vector<vector<int> > &A)
{
	int row = A.size(), col = A[0].size();
	bool rowFlag = false, colFlag = false;
	for(int i = 0; i < col; i++)
	{
		if(A[0][i] == 0)
		{
			rowFlag = true;
			break;
		}
	}
	for(int i = 0; i < row; i++)
	{
		if(A[i][0] == 0)
		{
			colFlag = true;
			break;
		}
	}
	for(int i = 1; i < row; i++)
	{
		for(int j = 1; j < col; j++)
		{
			if(A[i][j] == 0)
			{
				A[i][0] = 0;
				A[0][j] = 0;
			}
		}
	}
	for(int i = 1; i < row; i++)
	{
		for(int j = 1; j < col; j++)
		{
			if(A[i][0] == 0 || A[0][j] == 0)
				A[i][j] = 0;
		}
	}
	if(colFlag == true)
	{
		for(int i = 0; i < row; i++)
			A[i][0] = 0;
	}
	if(rowFlag == true)
	{
		for(int i = 0; i < col; i++)
			A[0][i] = 0;
	}
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > A(3, vector<int> (3));
	A[0][0] = 1; A[0][1] = 0; A[0][2] = 2;
	A[1][0] = 0; A[1][1] = 1; A[1][2] = 1;
	A[2][0] = 1; A[2][1] = 2; A[2][2] = 1;
	for(int i = 0; i < A.size(); i++)
	{
		for(int j = 0; j < A[0].size(); j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
	setZero(A);
	cout<<endl;
	for(int i = 0; i < A.size(); i++)
	{
		for(int j = 0; j < A[0].size(); j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}