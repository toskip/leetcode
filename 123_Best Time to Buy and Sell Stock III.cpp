class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<int> dp(n,0);
        vector<int> dp2(n,0);
        int minprice = prices[0];
        for(int i = 1;i<n;i++)
        {
            minprice = min(minprice,prices[i]);
            dp[i] = max(dp[i-1],prices[i]-minprice);
        }
        int maxprice = prices[n-1];
        for(int i = n-2;i>=0;i--)
        {
            maxprice = max(maxprice,prices[i]);
            dp2[i] = max(dp2[i+1],maxprice-prices[i]);
        }
        int result = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            result = max(result,dp[i]+dp2[i]);
        }
        return result;
    }
};
