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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* result = new ListNode(0);
        result->next = head;
        head = result;
        while(head->next)
        {
            if(head->next->val==val) head->next = head->next->next;
            else head = head->next;
        }
        return result->next;
    }
};
