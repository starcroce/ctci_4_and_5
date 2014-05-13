// use two pointers to move forward and check duplicate
#include "MyLinkedList.h"
#include <set>

// two pointers, time O(n^2), space O(1)
void removeDuplicates1(ListNode *head)
{
	if(head == NULL)
		return;
	ListNode *tmp1 = head;
	while(tmp1 != NULL)
	{
		int tmpData = tmp1->data;
		ListNode *tmp2 = tmp1, *tmp3 = tmp1->next;
		while(tmp3 != NULL)
		{
			if(tmp3->data == tmpData)
			{
				tmp2->next = tmp3->next;
				tmp3 = tmp2->next;
			}
			else
			{
				tmp2 = tmp3;
				tmp3 = tmp3->next;
			}
		}
		tmp1 = tmp1->next;
	}
}

// hash set, time O(n), space O(n)
void removeDuplicates2(ListNode *head)
{
	if(head == NULL)
		return;
	set<int> table;
	ListNode *tmp1 = head, *tmp2 = head->next;
	table.insert(tmp1->data);
	while(tmp2 != NULL)
	{
		if(table.find(tmp2->data) == table.end())
		{
			table.insert(tmp2->data);
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		else
		{
			tmp1->next = tmp2->next;
			tmp2 = tmp2->next;
		}
	}
}

int main(int argc, char const *argv[])
{
	int n = 5;
	int a[] = {1,3,3,1,4};
	ListNode *head1 = init(a, n);
	removeDuplicates1(head1);
	printList(head1);

	int m = 5;
	int b[] = {1,3,2,1,4};
	ListNode *head2 = init(b, m);
	removeDuplicates2(head2);
	printList(head2);
	return 0;
}