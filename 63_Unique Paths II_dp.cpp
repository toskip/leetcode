//参照答案重写了一下结构，果然这样比较好
int dp[101][101];
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        dp[0][1] = 1;
        for(int i=1;i<=m;++i)
        {
            for(int j = 1;j<=n;++j)
            {
                if(obstacleGrid[i-1][j-1]==1) dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
