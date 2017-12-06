//编辑距离 解释：http://www.stanford.edu/class/cs124/lec/med.pdf
int dp[800][800];
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        for(int i = 0;i<=m;i++)
        {
            dp[i][0] = i;
        }
        for(int j = 0;j<=n;j++)
        {
            dp[0][j] = j;
        }
        
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                int sub  = word1[i-1]==word2[j-1]?0:1;
                dp[i][j] = min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+sub);
            }
        }
        /*
        for(int i = 0;i<=m;i++)
        {
            for(int j = 0;j<=n;j++)
            {
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
        */
        return dp[m][n];
    }
};
