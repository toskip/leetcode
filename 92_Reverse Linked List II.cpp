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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        ListNode* cur =new ListNode(0);
        cur->next = head;
        head = cur;
        for(int i = 0;i<m-1;i++) cur = cur->next;
        ListNode* before = cur;
        cur = cur->next;
        ListNode* temp;
        for(int i = 0;i<n-m;i++)
        {
            temp = cur->next;
            cur->next=  temp->next;
            temp->next = before->next;
            before ->next = temp;
        }
        return head->next;
    }
};
