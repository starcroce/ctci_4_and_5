#include "MyLinkedList.h"

ListNode *reverseLinkedList(ListNode *head) {
	if(head == NULL) {
		return NULL;
	}
	ListNode *curr = head;
	ListNode *prev = NULL;
	while(curr != NULL) {
		ListNode *tmp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = tmp;
	}
	// prev is new head
	return prev;
}

int main(int argc, char const *argv[]) {
	int a[] = {1, 2, 3, 4};
	ListNode *head = init(a, 4);
	ListNode *newHead = reverseLinkedList(head);
	printList(newHead);
	return 0;
}