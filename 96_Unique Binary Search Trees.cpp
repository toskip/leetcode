//数学
class Solution {
public:
    int numTrees(int n) {
        int dp[100] = {0};
        dp[0] =1;
        for(int i = 1;i<=n;i++)
        {
            for(int j = 0;j<=(i-1)/2;j++)
            {
                if(j==i-1-j) dp[i]+=dp[j]*dp[i-1-j];
                else dp[i]+=dp[j]*dp[i-1-j]*2;
            }
        }
        return dp[n];
    }
};
