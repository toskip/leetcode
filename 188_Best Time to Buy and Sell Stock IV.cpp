class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k==0||n==0) return 0;
        if(k>=n/2)
        {
            int result = 0;
            for(int i = 1;i<n;i++)
            {
                if(prices[i]>prices[i-1])result+= prices[i]-prices[i-1];
            }
            return result;
        }
        vector<int> temp(n,0);
        vector<vector<int> > dp(k+1,temp);
        for(int i = 1;i<=k;i++)
        {
            int localmax = dp[i-1][0]-prices[0];
            for(int j = 1;j<n;j++)
            {
                dp[i][j] = max(dp[i][j-1],prices[j]+localmax);
                localmax = max(dp[i-1][j]-prices[j],localmax);
            }
        }
        return dp[k][n-1];
    }
};
