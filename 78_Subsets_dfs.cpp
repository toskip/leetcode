class Solution {
public:
    int n;
    vector<vector<int>> result;
    vector<int> current;
    void dfs(int start,int remain,vector<int>& nums)
    {
        if(remain==0) result.push_back(current);
        for(int i = start;i<n;i++)
        {
            current.push_back(nums[i]);
            dfs(i+1,remain-1,nums);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        for(int i = 0;i<=n;i++) dfs(0,i,nums);
        return result;
    }
};
