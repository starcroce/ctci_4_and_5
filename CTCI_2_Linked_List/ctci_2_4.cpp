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

node *addLists(node *p, node *q){
	if(p == NULL)
		return q;
	if(q == NULL)
		return p;
	int carry = 0;
	// ans is the head and pre is the tail
	node *ans, *pre = NULL;
	while(p && q){
		int tmp = p->data+q->data+carry;
		node *r = new node();
		r->data = tmp%10;
		if(pre){
			pre->next = r;
			pre = r;
		}
		else
			pre = ans = r;
		carry = tmp/10;
		p = p->next;
		q = q->next;
	}
	if(p){
		int tmp = p->data+carry;
		node *r = new node();
		r->data = tmp%10;
		pre->next = r;
		pre = r;
		carry = tmp/10;
		p = p->next;
	}
	if(q){
		int tmp = q->data+carry;
		node *r = new node();
		r->data = tmp%10;
		pre->next = r;
		pre = r;
		carry = tmp/10;
		q = q->next;
	}
	if(carry > 0){
		node *r =  new node();
		r->data = carry;
		pre->next = r;
	}
	return ans;
}

int main(){
	int m = 4, n = 3;
	int a[] = {1,2,9,3};
	int b[] = {2,3,5};
	node *p = init(a, m);
	node *q = init(b, n);
	node *ans = addLists(p, q);
	printList(ans);
	return 0;
}