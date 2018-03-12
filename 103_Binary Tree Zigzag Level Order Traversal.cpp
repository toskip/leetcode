//slighly modified from 102
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
    queue<TreeNode*> next;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool isreverse = true;
        if(root) next.push(root);
        while(!next.empty())
        {
            isreverse = !isreverse;
            int count = next.size();
            vector<int> temp;
            for(int i = 0;i<count;i++)
            {
                TreeNode* p = next.front();
                temp.push_back(p -> val);
                next.pop();
                if(p->left) next.push(p->left);
                if(p->right) next.push(p->right);
            }
            if(isreverse) reverse(temp.begin(),temp.end());
            result.push_back(temp);
        }
        return result;
    }
};
