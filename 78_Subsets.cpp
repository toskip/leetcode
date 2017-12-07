class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    int n,k;
    void dfs(int start,int numbers,vector<int>& nums)
    {
        if(numbers==k)
        {
            result.push_back(current);
            return;
        }
        for(int i = start;i<n;i++)
        {
                current.push_back(nums[i]);
                dfs(i+1,numbers+1,nums);
                current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        for(int i = 0;i<=n;i++)
        {
            k = i;
            dfs(0,0,nums);
        }
        return result;
    }
};
