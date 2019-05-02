//归并排序
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
    void swap(ListNode*p1,ListNode*p2){
        ListNode* temp = p2->next->next;
        p2->next->next = p1->next;
        p1->next = p2->next;
        p2->next = temp;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* p1 = head;
        int length = 0;
        while(p1){
            p1 = p1->next;
            length++;
        }
        p1 = new ListNode(0);
        p1->next = head;
        head = p1;
        int stride = 1;
        while(stride<length){
            p1 = head;
            ListNode* p2 = p1;
            for(int i = 0;i<=length/(stride*2);i++)
            {
                p1 = p2;
                bool stop = false;
                for(int j = 0;j<stride;j++){
                    if(!p2->next){
                        stop = true;
                        break;
                    }
                    p2 = p2->next;
                }
                if(stop) break;
                int p2count = 0;
                while(p2count<stride&&p1!=p2&&p2->next){
                    if(p2->next->val<p1->next->val){
                        swap(p1,p2);
                        p2count++;
                    }
                    else{
                        p1 = p1->next;
                    }
                }
                while(p2count++<stride&&p2->next){
                    p2 = p2->next;
                }
                
            }
            stride<<=1;
        }
        return head->next;
    }
};
