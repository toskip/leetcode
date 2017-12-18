class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result(1,vector<int>());
        int n = nums.size();
        int m;
        int startpos;
        for(int i = 0;i<n;i++)
        {
            if(i!=0 &&nums[i-1]==nums[i]) startpos = m;
            else startpos = 0;
            m = result.size();
            for(int j = startpos;j<m;j++)
            {
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
        }
        return result;
    }
};
