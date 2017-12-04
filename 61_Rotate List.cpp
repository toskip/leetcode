/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//没啥意思 光拿边界值坑人
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* address[3000];
        int count = 0;
        ListNode* cur = head;
        while(cur!=NULL)
        {
            address[count] = cur;
            count++;
            cur = cur->next;
        }
        
        if(count<=1 ||k%count==0) return head;
        k%=count;
        address[count-1]->next = address[0];
        address[count-k-1]->next = NULL;
        return address[count-k];
    }
};
