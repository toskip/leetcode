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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* a = headA;
        ListNode* b = headB;
        int counta = 0;
        int countb = 0;
        while(a)
        {
            a = a->next;
            counta++;
        }
        while(b)
        {
            b = b->next;
            countb++;
        }
        if(counta>countb)
        {
            for(int i = 0;i<counta-countb;i++)
            {
                headA = headA->next;
            }
        }
        else
        {
            for(int i = 0;i<countb-counta;i++)
            {
                headB = headB->next;
            }
        }
        while(headA!=headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
