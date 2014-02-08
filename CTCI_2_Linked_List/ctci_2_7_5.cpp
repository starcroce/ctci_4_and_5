#include <iostream>
#include <stack>
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

bool isPalindrome(node *head){
	node *fast = head;
	node *slow = head;
	stack<int> s;
	// push the first half into stack
	while(fast != NULL && fast->next != NULL){
		s.push(slow->data);
		fast = fast->next->next;
		slow = slow->next;
	}
	// move to the next half
	if(fast != NULL){
		slow = slow->next;
	}
	// pop the stack and compare it with next half of the list
	while(slow != NULL){
		int val = s.top();
		if(val != slow->data){
			return false;
		}
		s.pop();
		slow = slow->next;
	}
	return true;
}

int main(){
	int a[] = {1,2,2,1};
	int b[] = {1,2,3,2,1};
	int c[] = {1,2,3};
	node *head1 =  init(a, 4);
	node *head2 =  init(b, 5);
	node *head3 =  init(c, 3);
	cout<<isPalindrome(head1)<<" "<<isPalindrome(head2)<<" "<<isPalindrome(head3)<<" "<<endl;
	return 0;
}