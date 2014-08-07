#include <iostream>
using namespace std;

// magic index is A[i] = i
// if the input is sorted, can use binary search
int magicIndex(int A[], int len) {
	int start = 0, end = len - 1;
	while(start <= end) {
		int mid = (start + end) / 2;
		if(A[mid] == mid) {
			return mid;
		} else if(A[mid] > mid) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int A1[] = {-1, 1, 4, 10, 20};
	int A2[] = {-100, -40, -9, 3, 5};
	cout<<magicIndex(A1, 5)<<" "<<magicIndex(A2, 5)<<endl;
	return 0;
}