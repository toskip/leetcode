//之前那个是抄的，这个是自己写的，虽然有点墨迹
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
        ListNode* result = new ListNode(0);
        result->next = head;
        head = result;
        ListNode* beforestart = result;
        int i = 0;
        for(;i<m;i++)
        {
            beforestart = head;
            head = head->next;
        }
        ListNode* prev=NULL;
        ListNode* next;
        for(;i<=n;i++)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        beforestart->next->next = head;
        beforestart->next = prev;
        return result->next;
    }
};
