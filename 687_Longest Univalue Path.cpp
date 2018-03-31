//递归访问每个节点的时候返回两个值，第一个值是该节点下存在的最长路径，第二个值是以该节点为端点的最长路径
//思路和124差不多
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
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        pair<int,int> result = helper(root);
        return result.first;
    }
    pair<int,int> helper(TreeNode* root)
    {
        
        pair<int,int> result(0,0);
        pair<int,int> left(0,0);
        pair<int,int> right(0,0);
        if(root->left)
        {
            left = helper(root->left);
            if(root->val==root->left->val)
            {
                result.second = left.second+1;
                result.first+=left.second+1;
            }
        }
        if(root->right)
        {
            right = helper(root->right);
            if(root->val==root->right->val)
            {
                result.second = max(result.second,right.second+1);
                result.first+=right.second+1;
            }
        }
        result.first =max(result.first,max(left.first,right.first));
        return result;
    }
};
