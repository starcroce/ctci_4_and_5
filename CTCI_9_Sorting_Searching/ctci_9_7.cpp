#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct person{
	int height, weight;
};
person p[6];
int d[6];

// fist ensure height, then ensure weight
bool personComp(person p1, person p2){
	if(p1.height == p2.height)
		return p1.weight < p2.weight;
	else
		return p1.height < p2.height;
}

// find the longest sequence contains increasing heights and weights
// the original is sort by height, find the longest seq with increasing weights
int listPerson(person p[], int n){
	int k = 1;
	d[0] = p[0].weight;
	for(int i=1; i<n; i++){
		// if the next person is weighter than the prev one
		if(p[i].weight >= d[k-1])
			d[k++] = p[i].weight;
		// if the next person is lighter than the prev one
		else{
			cout<<i<<" "<<k<<endl;
			// update index of d to let p[i].weight can be inserted
			for(int j=k-1; j>=0 && d[j]>p[i].weight; j--){
				d[j+1] = p[i].weight;
			}
		}
	}
	return k;
}

int main(){
	freopen("9_7.in", "r", stdin);
	for(int i=0; i<6; i++){
		cin>>p[i].height>>p[i].weight;
	}
	sort(p, p+6, personComp);
	for(int i=0; i<6; i++){
		cout<<"("<<p[i].height<<" "<<p[i].weight<<") ";
	}
	cout<<endl;
	cout<<"The longest tower is length "<<listPerson(p, 6)<<endl;
	fclose(stdin);
	return 0;
}