//巨蠢
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
        ListNode* prev;
        ListNode* cur =new ListNode(0);
        cur->next = head;
        head = cur;
        ListNode* next;
        int count = -1;
        ListNode* start;
        ListNode* end;
        bool reverse = false;
        bool ok =true;
        while(ok)
        {
            ++count;
            //cout<<count<<endl;
            if(count==m-1)
            {
                start =cur;
                end = cur->next;
                prev = cur->next;
            }
            else if(count==m+1)
            {
                reverse =true;
            }
            if(count==n)
            {
                start->next = cur;
                end->next = cur->next;
                ok = false;
            }
            if(reverse)
            {
                next= cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head->next;
    }
};
