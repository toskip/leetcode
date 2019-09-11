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
    bool isPalindrome(ListNode* head) {
        long long temp = 0;
        int count= 0;
        ListNode* cur = head;
        while(cur){
            count++;
            cur = cur->next;
        }
        ListNode* next = NULL;
        cur = head;
        ListNode* prev;
        for(int i  = 0;i<count/2;i++){
            prev = cur->next;
            cur->next = next;
            next = cur;
            cur = prev;
        }
        ListNode* reverse = next;
        if(count%2!=0) cur = cur->next;
        while(cur && reverse && cur->val==reverse->val){
            cur = cur->next;
            reverse = reverse->next;
        }
        if(cur==NULL and reverse==NULL){return true;}
        else{return false;}
    }
};
