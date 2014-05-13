#include "MyLinkedList.h"

ListNode *addLists(ListNode *node1, ListNode *node2)
{
	if(node1 == NULL)
		return node2;
	if(node2 == NULL)
		return node1;
	int carry = 0;
	ListNode *fakeHead = new ListNode(), *head = fakeHead;
	while(node1 != NULL && node2 != NULL)
	{
		int val = node1->data + node2->data + carry;
		carry = val / 10;
		head->next = new ListNode();
		head->next->data = val % 10;
		head = head->next;
		node1 = node1->next;
		node2 = node2->next;
	}
	ListNode *remain = node1? node1: node2;
	while(remain != NULL)
	{
		int val = remain->data + carry;
		carry = val / 10;
		head->next = new ListNode();
		head->next->data = val % 10;
		head = head->next;
		remain = remain->next;
	}
	if(carry > 0)
	{
		head->next = new ListNode();
		head->next->data = carry % 10;
		head = head->next;
		carry /= 10;
	}
	return fakeHead->next;
}

int main(int argc, char const *argv[])
{
	int m = 4, n = 3;
	int a[] = {1,2,9,3};
	int b[] = {2,3,5};
	ListNode *p = init(a, m);
	ListNode *q = init(b, n);
	ListNode *ans = addLists(p, q);
	printList(ans);
	return 0;
}