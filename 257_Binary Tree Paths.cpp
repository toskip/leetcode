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
    vector<int> path;
    vector<string> result;
    void digui(TreeNode* cur){
        //cout<<cur->val<<endl;
        //cout<<path<<endl;
        if(!cur->left&&!cur->right){
            string temp = "";
            for(int i = 0;i<path.size()-1;i++){
                temp+=to_string(path[i])+"->";
            }
            temp+=to_string(path[path.size()-1]);
            result.push_back(temp);
            return;
        }
        if(cur->left){
            path.push_back(cur->left->val);
            digui(cur->left);
            path.pop_back();
        }
        if(cur->right){
            path.push_back(cur->right->val);
            digui(cur->right);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        if(root){
            path.push_back(root->val);
            digui(root);
        }
        
        return result;
    }
};
