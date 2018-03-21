
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(!n) return 0;
        int amin[30000];
        int amax[30000];
        amin[0] = prices[0];
        amax[n-1] = prices[n-1];
        for(int i = 1;i<n;i++)
        {
            amin[i] = min(amin[i-1],prices[i]);
            amax[n-1-i] = max(amax[n-i],prices[n-1-i]);
        }
        int result = 0;
        for(int i =0;i<n;i++)
        {
            result = max(result,amax[i]-amin[i]);
        }
        return result;
    }
};
