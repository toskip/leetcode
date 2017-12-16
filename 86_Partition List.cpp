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
    ListNode* partition(ListNode* head, int x) {
        ListNode* xiaoyuhead = new ListNode(0);
        ListNode* dayuhead = new ListNode(0);
        ListNode* xiaoyu = xiaoyuhead;
        ListNode* dayu = dayuhead;
        while(head)
        {
            if(head->val<x)
            {
                xiaoyu->next = head;
                xiaoyu = xiaoyu->next;
            }
            else
            {
                dayu->next = head;
                dayu = dayu->next;
            }
            head = head->next;
        }
        dayu->next = NULL;
        xiaoyu->next = dayuhead->next;
        return xiaoyuhead->next;
    }
};
