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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode*slow = head;
        do
        {
            if(!fast||! fast->next) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }
        while(fast!=slow);
        ListNode* start =head;
        while(1)
        {
            ListNode* fast=start;
            ListNode* slow = start;
            do
            {   
                slow = slow->next;
                fast = fast->next->next;
            }
            while(fast!=slow);
            if(slow==start) return start;
            start = start->next;
        }
    }
};
