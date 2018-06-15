class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int value;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(!count) value = nums[i];
            if(value==nums[i]) count++;
            else count--;
        }
        return value;
    }
};
