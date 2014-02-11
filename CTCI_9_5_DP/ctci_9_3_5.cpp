// magic index is A[i] = i
// regular solution
int magicIndex(vector<int> &num) {
	for(int i = 0; i < num.size(); i++) {
		if(num[i] == i) {
			return i
		}
	}
	return -1;
}

// if the input is sorted, can use binary search
int magicIndex(vector<int> &num) {
	int start = 0;
	int end = num.size() - 1;
	if(start > end) {
		return -1;
	}
	while(start <= end) {
		int mid = (start + end) / 2;
		if(num[mid] == mid) {
			return mid;
		}
		// can draw a plot to see the detailed condition
		if(num[mid] > mid) {
			end = mid - 1;
		}
		if(num[mid] < mid) {
			start = mid + 1;
		}
	}
	return -1;
}