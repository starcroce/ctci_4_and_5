#include <iostream>
using namespace std;

typedef struct ListNode
{
	int data;
	ListNode *next;
} ListNode;

ListNode *init(int a[], int n)
{
	ListNode *head, *p;
	for(int i = 0; i < n; i++){
		ListNode *n = new ListNode();
		n->data = a[i];
		if(i == 0)
		{
			head = p = n;
			continue;
		}
		p->next = n;
		p = n;
	}
	return head;
}

void printList(ListNode *head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}