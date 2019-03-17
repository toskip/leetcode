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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int count =0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* root = q.front();
            q.pop();
            count++;
            if(root->left)
            {
                q.push(root->left);
            }
            if(root->right)
            {
                q.push(root->right);
            }
        }
        return count;
    }
};
