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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = new ListNode(0);
        cur->next = head;
        head = cur;
        int value;
        while(cur && cur->next && cur->next->next)
        {
            if(cur->next->val==cur->next->next->val)
            {
                value = cur->next->val;
                while(cur->next&&cur->next->val==value) cur->next=cur->next->next;
            }
            else cur = cur->next;
        }
        return head->next;
    }
};
