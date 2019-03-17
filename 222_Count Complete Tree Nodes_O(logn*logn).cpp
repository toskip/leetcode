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
private:
    int middleDepth(TreeNode* root)
    {
        TreeNode* temp = root;
        int count = 0;
        temp = temp->left;
        while(temp)
        {
            count++;
            temp = temp -> right;
        }
        return count;
    }
public:
    
    int countNodes(TreeNode* root) 
    {
        if(!root) return 0;
        TreeNode* temp = root;
        int left = 1;
        int right=1;
        while(temp->left)
        {
            temp = temp->left;
            left++;
        }
        temp = root;
        while(temp->right)
        {
            temp = temp->right;
            right++;
        }
        if(left==right)
        {
            return (1<<left)-1;
        }
        int current = 1;
        int depth=1;
        cout<<left<<" "<<right<<endl;
        while(depth< left)
        {
            
            int middle = middleDepth(root);
            cout<<current<<" "<<middle<<" "<<depth<<endl;
            if(middle+depth<left)
            {
                right = middle+depth;
                root = root->left;
                current = current<<1;
            }
            else
            {
                left = middle+depth;
                root = root->right;
                current = (current<<1)+1;
            }
            depth++;
        }
        return current-1;
    }
};
