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
    int result = 0;
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        helper(root,0);
        return result;
    }
    void helper(TreeNode* root, int value)
    {
        value = value*10+root->val;
        if(!root->left &&!root->right)
        {
            result+=value;
        }
        else
        {
            if(root->left) helper(root->left,value);
            if(root->right) helper(root->right,value);
        }
    }
    
};
