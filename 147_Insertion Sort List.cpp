
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* first = new ListNode(0);
        first->next = head;
        ListNode* cur = head;
        while(cur &&cur->next){
            ListNode* pos = first;
            while(pos->next->val<cur->next->val&&pos!=cur) pos = pos->next;
            if(pos==cur){
                cur = cur->next;
            }
            else{
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                temp->next = pos->next;
                pos->next = temp;
            }
        }
        return first->next;
    }
};

