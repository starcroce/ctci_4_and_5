#include "MyLinkedList.h"

ListNode *removeTargetNode(ListNode *head, int target) {
	if(head == NULL) {
		return NULL;
	}
	ListNode *fakeHead = new ListNode();
	fakeHead->next = head; fakeHead->data = -1;
	ListNode *prev = fakeHead, *curr = head;
	while(curr != NULL) {
		if(curr->data == target) {
			// if curr is target node, change the next ptr of prev
			prev->next = curr->next;
			// update the pos of curr
			curr = prev->next;
		} else {
			prev = curr;
			curr = curr->next;
		}
	}
	return fakeHead->next;
}

int main(int argc, char const *argv[]) {
	int a[] = {2, 1, 2, 3, 2, 2, 5, 2};
	ListNode *head = init(a, 8);
	ListNode *res = removeTargetNode(head, 2);
	printList(res);
	return 0;
}