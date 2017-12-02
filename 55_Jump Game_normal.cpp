//正常做法，很慢
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool dp[30000] = {0};
        dp[0] = 1; 
        for(int i=0;i<nums.size();i++)
        {
            if(dp[i]==0) continue;
            if(i==nums.size()-1)
            {
                return true;
            }
            for(int j=1;j<=nums[i];j++)
            {
                dp[i+j] = 1;
            }
        }
        return false;
        
    }
};
