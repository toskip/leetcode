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
    void reorderList(ListNode* head) {
        if(!head) return;
        vector<ListNode*> array;
        while(head)
        {
            array.push_back(head);
            head = head->next;
        }
        int i  =0;
        int j = array.size()-1;
        while(i<j)
        {
            array[j]->next = array[i]->next;
            array[i]->next = array[j];
            i++;j--;
        }
        array[i]->next = NULL;
        
    }
};
