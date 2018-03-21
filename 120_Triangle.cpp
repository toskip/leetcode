//dp
int dp[500][500];
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int k = triangle.size();
        dp[0][0] = triangle[0][0];
        for(int i =1;i<k;i++) dp[i][0] = triangle[i][0]+dp[i-1][0];
        for(int i =1;i<k;i++)
        {
            for(int j=1;j<i;j++) 
            {
                dp[i][j] = min(dp[i-1][j-1]+triangle[i][j],dp[i-1][j]+triangle[i][j]);
            }
            dp[i][i] = dp[i-1][i-1]+triangle[i][i];
        }
        int min = INT_MAX;
        for(int j = 0;j<k;j++)
        {
            if(dp[k-1][j]<min) min = dp[k-1][j];
        }
        return min;
    }
};
