#include <iostream>
#include <cstring>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node *init(int a[], int n){
	node *head, *p;
	for(int i=0; i<n; i++){
		node *n = new node();
		n->data = a[i];
		if(i == 0){
			head = p = n;
			continue;
		}
		p->next = n;
		p = n;
	}
	return head;
}

node *findNthToLast(node *head, int n){
	if(head==NULL || n<1)
		return NULL;
	node *p = head, *q = head;
	for(int i=0; i<n; i++){
		q = q->next;
	}
	while(q){
		p = p->next;
		q = q->next;
	}
	return p;
}

int main(){
	int n = 10;
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	node *head = init(a, n);
	node *result = findNthToLast(head, 5);
	cout<<result->data<<endl;
	return 0;
}