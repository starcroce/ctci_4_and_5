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

void printList(node *head){
	while(head){
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

bool remove(node *n){
	if(n==NULL || n->next==NULL)
		return false;
	node *t = n->next;
	n->data = t->data;
	n->next = t->next;
	return true;
}

int main(){
	int n = 5;
	int a[] = {1,3,2,4,5};
	node *head = init(a, n);
	int c = 3;
	node *t = head;
	for(int i=1; i<c; i++){
		t = t->next;
	}
	if(remove(t))
		printList(head);
	return 0;
}