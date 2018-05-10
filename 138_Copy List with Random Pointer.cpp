/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode* current = new RandomListNode(head->label);
        RandomListNode* result = current;
        map<RandomListNode*,RandomListNode*> lookup;
        while(head)
        {
            if(head->next)
            {
                if(lookup.find(head->next)==lookup.end()) 
                {
                    current ->next = new RandomListNode(head->next->label);
                    lookup[head->next] = current->next;
                }
                else current->next = lookup[head->next];
            }
            if(head->random)
            {
                if(lookup.find(head->random)==lookup.end()) 
                {
                    current ->random = new RandomListNode(head->random->label);
                    lookup[head->random] = current->random;
                }
                else current->random = lookup[head->random];
            }
            head = head->next;
            current = current->next;
        }
        return result;
    }
};
