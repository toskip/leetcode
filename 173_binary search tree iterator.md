class BSTIterator {
private:
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        if(root)
        {
            s.push(root);
            while(root->left){
                s.push(root->left);
                root = root->left;
            }
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* cur = s.top();
        s.pop();
        int result = cur->val;
        if(cur->right){
            s.push(cur->right);
            cur = cur->right;
            while(cur->left){
                s.push(cur->left);
                cur = cur->left;
            }
        }
        return result;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
};
