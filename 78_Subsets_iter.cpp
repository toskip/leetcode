class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result(1,vector<int>());
        vector<int> temp;
        int n = nums.size();
        int m;
        for(int i = 0;i<n;i++)
        {
            m = result.size();
            for(int j =0;j<m;j++)
            {
                temp = result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }
        return result;
    }
};
