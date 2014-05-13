#include "MyLinkedList.h"

ListNode *partition(ListNode *head, int target)
{
	ListNode *beforeStart = NULL, *beforeEnd = NULL;
	ListNode *afterStart = NULL, *afterEnd = NULL;
	while(head != NULL)
	{
		if(head->data < target)
		{
			if(beforeStart == NULL)
			{
				beforeStart = head;
				beforeEnd = head;
			}
			else
			{
				beforeEnd->next = head;
				beforeEnd = beforeEnd->next;
			}
			head = head->next;
			beforeEnd->next = NULL;
		}
		else
		{
			if(afterStart == NULL)
			{
				afterStart = head;
				afterEnd = head;
			}
			else
			{
				afterEnd->next = head;
				afterEnd = afterEnd->next;
			}
			head = head->next;
			afterEnd->next = NULL;
		}
	}
	if(beforeStart == NULL)
		return afterStart;
	beforeEnd->next = afterStart;
	return beforeStart;
}

int main(int argc, char const *argv[])
{
	int a[] = {5,2,4,1,3,7,6};
	ListNode *head = init(a, 7);
	ListNode *res = partition(head, 4);
	printList(res);
	return 0;
}