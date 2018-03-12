//slightly modified from 105
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
    vector<int> postorder;
    vector<int> inorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = postorder.size();
        if(!len) return NULL;
        this->postorder = postorder;
        this->inorder = inorder;
        for(int i =0;i<len;i++)
        {
            rinorder[inorder[i]] = i;
        }
        pos = len-1;
        int mid = rinorder[postorder[pos]];
        TreeNode* root = new TreeNode(postorder[pos--]);
        root->right = recur(mid+1,len-1);
        root->left = recur(0,mid-1);
        return root;
    }
    TreeNode* recur(int low,int high)
    {
        if(low>high) return NULL;
        else if(low==high) return new TreeNode(postorder[pos--]);
        else
        {
            int mid = rinorder[postorder[pos]];
            TreeNode* root = new TreeNode(postorder[pos--]);
            root->right = recur(mid+1,high);
            root->left = recur(low,mid-1);
            return root;
        }
    }
};
