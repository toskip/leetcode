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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<pair<TreeNode*,int> > bfs;
        if(root) bfs.push(make_pair(root,0));
        while(!bfs.empty())
        {
            TreeNode* cur = bfs.front().first;
            int depth = bfs.front().second;
            bfs.pop();
            if(cur->left) bfs.push(make_pair(cur->left,depth+1));
            if(cur->right) bfs.push(make_pair(cur->right,depth+1));
            if(bfs.empty()||bfs.front().second>depth) result.push_back(cur->val);
        }
        return result;
    }
};
