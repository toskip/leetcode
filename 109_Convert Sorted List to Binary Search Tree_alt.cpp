class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head,ListNode* tail = NULL) {
        if(!head) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=tail &&fast->next!=tail)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast!=tail) fast = fast->next;
        TreeNode* root = new TreeNode(slow->val);
        if(head!=slow) root->left = sortedListToBST(head,slow);
        if(slow->next!=fast) root->right = sortedListToBST(slow->next,fast);
        return root;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
