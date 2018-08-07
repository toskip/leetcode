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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* result = l3;
        bool jinwei = 0;
        int val;
        while(l1||l2)
        {
            val = (l1?l1->val:0)+(l2?l2->val:0)+jinwei;
            l3->next = new ListNode(val%10);
            jinwei = val/10;
            l3 = l3->next;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
        }
        if(jinwei) l3->next = new ListNode(jinwei);
        return result->next;
    }
};
