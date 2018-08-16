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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newhead = new ListNode(0);
        newhead->next = head;
        ListNode* cur = newhead;
        ListNode* result = newhead;
        while(n)
        {
            n--;
            cur = cur->next;
        }
        while(cur->next)
        {
            cur = cur->next;
            result = result->next;
        }
        if(result->next) result->next = result->next->next;
        return newhead->next;
    }
};
