#include <iostream>
#include <cstring>
using namespace std;

typedef struct node{
	int data;
	node *next;
}node;

node *init(int a[], int n, int m){
	node *head, *p, *q;
	for(int i=0; i<n; i++){
		node *t = new node();
		t->data = a[i];
		if(i == 0){
			head = p = t;
			continue;
		}
		if(i == m)
			q = t;
		p->next = t;
		p = t;
	}
	p->next = q;
	return head;
}

node *loopStart(node *head){
	if(head == NULL)
		return NULL;
	node *fast = head;
	node *slow = head;
	// the condition is fast->next and fast != NULL
	while(fast->next != NULL && fast != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow)
			break;
	}
	// if no loop
	if(fast->next == NULL || fast == NULL)
		return NULL;
	slow = head;
	while(fast != slow){
		fast = fast->next;
		slow = slow->next;
	}
	return fast;
}

int main(){
	int m = 9, n = 10;
	int a[] = {3,2,1,3,5,6,2,6,3,1};
	node *head = init(a, n, m);
	node *p = loopStart(head);
	cout<<p->data<<endl;
	return 0;
}