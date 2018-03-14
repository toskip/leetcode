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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left==-1||right==-1||abs(left-right)>1) return false;
        else return true;
    }
    int depth(TreeNode* cur)
    {
        if(!cur) return 0;
        int left = depth(cur->left);
        int right = depth(cur->right);
        if(left==-1||right==-1||abs(left-right)>1) return -1;
        else return max(left,right)+1;
    }
};
