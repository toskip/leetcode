class Solution {
public:
    vector<int> nums;
    TreeNode* sortedListToBST(ListNode* head) {
        while(head!=NULL)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        sort(nums.begin(),nums.end());
        int high = nums.size();
        high--;
        int low=0;
        if(low>high) return NULL;
        int mid = (low+high)/2;
        TreeNode* root = new TreeNode(this->nums[mid]);
        root->left = recur(low,mid-1);
        root->right = recur(mid+1,high);
        return root;
    }
    TreeNode* recur(int low,int high)
    {
        if(low>high) return NULL;
        int mid = (low+high)/2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = recur(low,mid-1);
        cur->right = recur(mid+1,high);
        return cur;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
