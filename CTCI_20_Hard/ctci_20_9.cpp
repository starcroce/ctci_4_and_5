#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

// the median will be the largest value of the max heap and if the a new value arrives, it will be placed in the below heap if the value is less than or equal to the median, otherwise it is placed into the above heap
// the heap size can be equal or has one diff

class Median{
public:
	void insert(int n);
	int getValue();
private:
	// a max heap for the values below the median
	// a min heap for the values above the median
	priority_queue<int, vector<int>, less<int> > maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
};

void Median::insert(int n){
	if(maxHeap.empty() && minHeap.empty())
		maxHeap.push(n);
	else if(!maxHeap.empty() && minHeap.empty())
		maxHeap.push(n);
	else if(maxHeap.empty() && !minHeap.empty())
		minHeap.push(n);
	else{
		if(n < maxHeap.top())
			maxHeap.push(n);
		else
			minHeap.push(n);
	}
	while(maxHeap.size() > minHeap.size()+1){
		int data = maxHeap.top();
		minHeap.push(data);
		maxHeap.pop();
	}
	while(minHeap.size() > maxHeap.size()+1){
		int data = minHeap.top();
		maxHeap.push(data);
		minHeap.pop();
	}
}

int Median::getValue(){
	if(maxHeap.empty() && minHeap.empty())
		// return the minimun value if both heaps are empty
		return 1<<31;
	if(maxHeap.size() == minHeap.size())
		return (maxHeap.top()+minHeap.top())/2;
	else if(maxHeap.size() > minHeap.size())
		return maxHeap.top();
	else
		return minHeap.top();
}

int main(){
	srand((unsigned)time(NULL));
	Median md;
	vector<int> vi;
	int num = rand() % 30;
	for(int i=0; i<num; i++){
		int data = rand() % 100;
		vi.push_back(data);
		md.insert(data);
	}
	sort(vi.begin(), vi.end());
	for(int i=0; i<num; i++){
		cout<<vi.at(i)<<" ";
	}
	cout<<endl<<md.getValue()<<endl;
	return 0;
}