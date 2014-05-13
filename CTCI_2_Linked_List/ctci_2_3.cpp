#include "MyLinkedList.h"

void removeMiddleNode(ListNode *node)
{
	if(node == NULL || node->next == NULL)
		return;
	ListNode *tmp = node->next;
	node->data = tmp->data;
	node->next = tmp->next;
}

int main(int argc, char const *argv[])
{
	int n = 5;
	int a[] = {1,3,2,4,5};
	ListNode *head = init(a, n);
	removeMiddleNode(head->next->next);
	printList(head);
	return 0;
}