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
    vector<vector<int>> result;
    vector<int> current;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root) return result;
        helper(root,sum);
        return result;
    }
    void helper(TreeNode* root,int sum)
    {
        current.push_back(root->val);
        if(!root->left && !root->right &&sum==root->val) result.push_back(current);
        else
        {
            if(root->left) helper(root->left,sum-root->val);
            if(root->right) helper(root->right,sum-root->val);
        }
        current.pop_back();
    }
};
