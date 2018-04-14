class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        int i;
        for(i = nums.size()-1;i>0;i--)
        {
            if(nums[i-1]<nums[i])
            {
                int j;
                for(j = i;j<nums.size();j++)
                {
                    if(nums[j]<=nums[i-1]) break;
                }
                swap(nums[j-1],nums[i-1]);
                break;
            }
        }
        reverse(nums.begin()+i,nums.end());
    }
};
