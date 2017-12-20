//pre-order traversal is root-left-right, and post order is left-right-root. 
//modify the code for pre-order to make it root-right-left, and then reverse the output so that we can get left-right-root .
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode*> nodeStack;
        vector<int> result;
        if(root==NULL)
        return result;
        nodeStack.push(root);
        while(!nodeStack.empty())
        {
            TreeNode* node= nodeStack.top();  
            result.push_back(node->val);
            nodeStack.pop();
            if(node->left)
            nodeStack.push(node->left);
            if(node->right)
            nodeStack.push(node->right);
        }
     reverse(result.begin(),result.end());
     return result;
    }
};
