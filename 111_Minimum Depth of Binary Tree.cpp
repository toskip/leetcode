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
    queue<TreeNode*> q;
    int minDepth(TreeNode* root) {
        if(root) q.push(root);
        int count = 0;
        while(!q.empty())
        {
            count++;
            int len = q.size();
            for(int i = 0;i<len;i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                if(!cur->left && !cur->right) return count;
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
        }
        return count;
    }
};
