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
    int maxvalue =INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return maxvalue;
    }
    int helper(TreeNode* root)
    {
        if(!root) return INT_MIN;
        int left = helper(root->left);
        int right = helper(root->right);
        maxvalue = max(maxvalue,max(0,left)+max(0,right)+root->val);
        return max(0,max(left,right))+root->val;
    }
};
