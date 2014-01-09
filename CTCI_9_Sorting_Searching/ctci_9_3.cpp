#include <iostream>
using namespace std;

// find x in which part of the array and do binary search
int search(int a[], int low, int high, int x){
	while(low <= high){
		int mid = (low+high)/2;
		if(a[mid] == x)
			return mid;
		if(a[mid] < x){
			if(a[mid] < a[low]){
				if(a[low] <= x)
					high = mid-1;
				else
					low = mid+1;
			}
			else
				low = mid+1;
		}
		else{
			if(a[mid] < a[low])
				high = mid-1;
			else{
				if(a[low] <= x)
					high = mid-1;
				else
					low = mid+1;
			}
		}
	}
	return -1;
}

int main(){
	int a[12] = {
		15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14
	};
	cout<<search(a, 0, 11, 10)<<endl;
	return 0;
}