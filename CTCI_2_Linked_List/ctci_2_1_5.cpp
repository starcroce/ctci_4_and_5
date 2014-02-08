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

void removeDuplicate1(node *head){
	if(head == NULL){
		return;
	}
	map<int, bool> table;
	node *n = head;
	node *p = NULL;
	while(n != NULL){
		if(table.find(n->data) == table.end()){
			table[n->data] = true;
			p = n;
		}
		else{
			p->next = n->next;
		}
		n = n->next;
	}
}

void removeDuplicate2(node *head){
	if(head == NULL)
		return;
	node *p, *c = head;
	while(c){
		p = c;
		// another method is to use if-continue
		// like leetcode remove duplicate element from sorted list
		while(p->next){
			if(p->next->data == c->data){
				p->next = p->next->next;
			}
			else{
				p = p->next;
			}
		}
		c = c->next;
	}
}

int main(){
	int n = 5;
	int a[] = {1,3,3,1,4};
	node *head1 = init(a, n);
	node *head2 = init(a, n);
	removeDuplicate1(head1);
	removeDuplicate2(head2);
	printList(head1);
	printList(head2);
	return 0;
}