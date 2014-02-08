// same to leetcode "add two numbers"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!l1 && !l2)
            return new ListNode(0);
        ListNode *head = new ListNode(0), *phead = head;
        int adv = 0;
        while(l1 && l2) {
            int value = l1->val + l2->val + adv;
            adv = value / 10;
            phead->next = new ListNode(value%10);
            phead = phead->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        ListNode *remain = l1? l1: l2;
        while(remain) {
            int value = remain->val + adv;
            adv = value / 10;
            phead->next = new ListNode(value%10);
            phead = phead->next;
            remain = remain->next;
        }
        if(adv>0) {
            phead->next = new ListNode(adv%10);
            phead = phead->next;
            adv /= 10;
        }
        // remove the first node
        return head->next;
    }
};