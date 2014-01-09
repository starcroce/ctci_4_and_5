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

void removeDuplicates(node *head){
	if(head == NULL)
		return;
	node *p, *q, *c = head;
	while(c){
		p = c;
		q = c->next;
		int d = c->data;
		while(q){
			if(q->data == d){
				node *t = q;
				p->next = t->next;
				q = p->next;
				delete t;
			}
			else{
				p = q;
				q = q->next;
			}
		}
		c = c->next;
	}
}

int main(){
	int n = 5;
	int a[] = {1,3,3,1,4};
	node *head = init(a, n);
	removeDuplicates(head);
	printList(head);
	return 0;
}