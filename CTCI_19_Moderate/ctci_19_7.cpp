#include <iostream>
using namespace std;

int getMaxSum(int a[], int len){
	int maxSum = 1<<31, sum = 0;
	for(int i=0; i<len; i++){
		if(sum < 0)
			sum = a[i];
		else
			sum += a[i];
		if(sum > maxSum)
			maxSum = sum;
	}
	return maxSum;
}

int main(){
	int a[] = {2, -8, 3, -2, 4, -10};
	int b[] = {-13, -1, -8, 0, -5};
	int maxSum1 = getMaxSum(a, 6);
	int maxSum2 = getMaxSum(b, 5);
	cout<<maxSum1<<" "<<maxSum2<<endl;
	return 0;
}