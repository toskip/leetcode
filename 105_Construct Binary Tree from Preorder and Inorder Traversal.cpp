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
    map<int,int> rinorder;
    int pos;
    vector<int> preorder;
    vector<int> inorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if(!len) return NULL;
        this->preorder = preorder;
        this->inorder = inorder;
        for(int i =0;i<len;i++)
        {
            rinorder[inorder[i]] = i;
        }
        pos = 0;
        int mid = rinorder[preorder[pos]];
        TreeNode* root = new TreeNode(preorder[pos++]);
        root->left = recur(0,mid-1);
        root->right = recur(mid+1,len-1);
        return root;
    }
    TreeNode* recur(int low,int high)
    {
        if(low>high) return NULL;
        else if(low==high) return new TreeNode(preorder[pos++]);
        else
        {
            int mid = rinorder[preorder[pos]];
            TreeNode* root = new TreeNode(preorder[pos++]);
            root->left = recur(low,mid-1);
            root->right = recur(mid+1,high);
            return root;
        }
    }
};
