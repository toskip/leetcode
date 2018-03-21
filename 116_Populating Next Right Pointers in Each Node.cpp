/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<TreeLinkNode*> q;
        if(root) q.push(root);
        TreeLinkNode* cur;
        while(!q.empty())
        {
            int count = q.size();
            for(int i = 1;i<count;i++)
            {
                cur = q.front();
                q.pop();
                cur->next = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            cur = q.front();
            q.pop();
            cur->next = NULL;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
};
