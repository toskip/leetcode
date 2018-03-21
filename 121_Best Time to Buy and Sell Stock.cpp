class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minvalue = INT_MAX;
        int result = 0;
        for(int i = 0;i<n;i++)
        {
            minvalue = min(minvalue,prices[i]);
            result = max(result,prices[i]-minvalue);
        }
        return result;
    }
};
