#include "MyLinkedList.h"

ListNode *findNthToLast(ListNode *head, int n)
{
	if(head == NULL || n < 1)
		return NULL;
	ListNode *fast = head, *slow = head;
	for(int i = 0; i < n; i++)
		fast = fast->next;
	while(fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main(int argc, char const *argv[])
{
	int n = 10;
	int a[] = {1,2,3,4,5,6,7,8,9,0};
	ListNode *head = init(a, n);
	ListNode *result = findNthToLast(head, 5);
	cout<<result->data<<endl;
	return 0;
}