#include <iostream>
#include <vector>
using namespace std;

// assume the set has 4 elements, subset can be from 0001 to 1111
vector<vector<int> > getSubsets(int a[], int n){
    vector<vector<int> > subsets;
    int max = 1<<n;
    for(int i=0; i<max; i++){
        vector<int> subset;
        int idx = 0;
        int j = i;
        while(j > 0){
            if(j & 1){
                subset.push_back(a[idx]);
            }
            j >>= 1;
            idx++;
        }
        subsets.push_back(subset);
    }
    return subsets;
}

void printSubsets(vector<vector<int> > subsets){
	for(int i=0; i<subsets.size(); i++){
		vector<int> subset = subsets[i];
		for(int j=0; j<subset.size(); j++){
			cout<<subset[j]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int a[] = {1, 2, 3, 4};
	vector<vector<int> > sub = getSubsets(a, 4);
	printSubsets(sub);
	return 0;
}