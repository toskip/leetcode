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
    queue<TreeNode*> next;
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root) next.push(root);
        while(!next.empty())
        {
            depth++;
            int count = next.size();
            for(int i = 0;i<count;i++)
            {
                TreeNode* p = next.front();
                next.pop();
                if(p->left) next.push(p->left);
                if(p->right) next.push(p->right);
            }
        }
        return depth;
    }
};
