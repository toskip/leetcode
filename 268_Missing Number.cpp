class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int maxvalue = -1;
        for(int i = 0;i<n;)
        {
            if(nums[i]==i||nums[i]==-1) {i++;continue;}
            if(nums[i]==n) swap(maxvalue,nums[i]);
            else
            {
                swap(nums[i],nums[nums[i]]);
            }
        }
        int result = n;
        for(int i = 0;i<n;i++)
        {
            if(nums[i]==-1)
            {
                result = i;
                break;
            }
        }
        return result;
    }
};
