/* dp
https://leetcode.com/problems/distinct-subsequences/discuss/37327/Easy-to-understand-DP-in-Java
*/
int dp[1000][100000];
class Solution {
public:
    int numDistinct(string s, string t) {
        int lent = t.size();
        int lens = s.size();
        for(int i = 0;i<=lent;i++) dp[i][0] = 0;
        for(int j = 0;j<=lens;j++) dp[0][j] = 1;
        for(int i = 1;i<=lent;i++)
        {
            for(int j = 1;j<=lens;j++)
            {
                dp[i][j] = dp[i][j-1];
                if(t[i-1]==s[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[lent][lens];
    }
};
