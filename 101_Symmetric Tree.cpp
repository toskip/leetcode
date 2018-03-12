//slightly modified version of 100
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode* p = root->left;
        TreeNode* q = root->right;
        if((p==NULL &&q!=NULL)||(q==NULL&&p!=NULL)) return false;
        return (p==NULL&&q==NULL)||((p->val==q->val)&& isSameTree(p->right,q->left)&&isSameTree(p->left,q->right));
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p==NULL &&q!=NULL)||(q==NULL&&p!=NULL)) return false;
        return (p==NULL&&q==NULL)||((p->val==q->val)&& isSameTree(p->right,q->left)&&isSameTree(p->left,q->right));
    }
};
