class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n  = nums.size();
        vector<int> result;
        map<int,int> remain;
        for(int i = 0;i<n;i++)
        {
            if(remain.count(nums[i]))
            {
                result.push_back(remain[nums[i]]);
                result.push_back(i);
                return result;
            }
            else 
                remain[target-nums[i]] = i;
        }
        
    }
};
