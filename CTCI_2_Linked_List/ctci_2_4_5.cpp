#include <iostream>
#include <cstring>
#include <map>
using namespace std;

typedef struct node{
	int data;
	node *next;
} node;

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

void printList(node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

node *partition(node *head, int x){
	node *before = NULL;
	node *after = NULL;
	while(head){
		node *p = head->next;
		if(head->data < x){
			head->next = before;
			before = head;
		}
		else{
			head->next = after;
			after = head;
		}
		head = p;
	}
	if(before == NULL){
		return after;
	}
	node *res = before;
	while(before->next){
		before = before->next;
	}
	before->next = after;
	return res;
}

int main(){
	int a[] = {1,3,2,4,5,7,6};
	node *head = init(a, 7);
	node *res = partition(head, 4);
	printList(res);
	return 0;
}