class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        queue<int> cache;
        int sum = 0;
        int result = n+1;
        for(int i = 0;i<n;i++)
        {
            sum+=nums[i];
            cache.push(nums[i]);
            while(sum-cache.front()>=s)
            {
                sum-=cache.front();
                cache.pop();
            }
            if(sum>=s) result = cache.size()<result?cache.size():result;
        }
        if(result==n+1)result = 0;
        return result;
    }
};
