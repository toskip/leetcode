class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count  =0;
        int n = nums.size();
        for(int i =2;i<n;i++)
        {
            if(nums[i]==nums[i-count-2]) count++;
            else nums[i-count] = nums[i];
        }
        return n-count;
    }
};
