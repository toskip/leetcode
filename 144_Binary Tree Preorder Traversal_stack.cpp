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
    vector<int> result;
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return result;
        stack<TreeNode*> st;
        TreeNode* cur;
        st.push(root);
        while(!st.empty() )
        {
            cur = st.top();
            st.pop();
            result.push_back(cur->val);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return result;
    }
};
