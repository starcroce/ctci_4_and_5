#include "MyLinkedList.h"
#include <stack>

bool isPalindrome(ListNode *head)
{
	stack<int> s;
	ListNode *fast = head, *slow = head;
	while(fast != NULL && fast->next != NULL)
	{
		s.push(slow->data);
		fast = fast->next->next;
		slow = slow->next;
	}
	// in case of the length of linked list is odd
	if(fast != NULL)
		slow = slow->next;
	while(slow != NULL)
	{
		int tmp = s.top();
		if(tmp != slow->data)
			return false;
		s.pop();
		slow = slow->next;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int a[] = {1,2,2,1};
	int b[] = {1,2,3,2,1};
	int c[] = {1,2,3};
	ListNode *head1 =  init(a, 4);
	ListNode *head2 =  init(b, 5);
	ListNode *head3 =  init(c, 3);
	cout<<isPalindrome(head1)<<" "<<isPalindrome(head2)<<" "<<isPalindrome(head3)<<" "<<endl;
	return 0;
}