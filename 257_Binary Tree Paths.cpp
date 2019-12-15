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
    string path;
    vector<string> result;
    void digui(TreeNode* cur){
        //cout<<cur->val<<endl;
        //cout<<path<<endl;
        if(!cur->left&&!cur->right){
            result.push_back(path);
            return;
        }
        if(cur->left){
            path+="->"+to_string(cur->left->val);
            digui(cur->left);
            int i = path.size()-1;
            while(path[i]!='-'||!isdigit(path[i-1]))i--;
            path = path.substr(0,i);
        }
        if(cur->right){
            path+="->"+to_string(cur->right->val);
            digui(cur->right);
            int i = path.size()-1;
            while(path[i]!='-'||!isdigit(path[i-1]))i--;
            path = path.substr(0,i);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        if(root){
            path = to_string(root->val);
            digui(root);
        }
        
        return result;
    }
};
