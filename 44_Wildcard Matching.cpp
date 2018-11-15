//特别挫的dp 击败了2.79%
//https://leetcode.com/submissions/detail/189719094/
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<bool> temp(s.size()+1,0);
        vector<vector<bool> > dp(p.size()+1,temp);
        dp[0][0] = 1;
        for(int i = 1;i<=p.size();i++)
        {
            if(p[i-1]=='*') dp[i][0] = dp[i-1][0];
            for(int j = 1;j<=s.size();j++)
            {
                if(p[i-1]=='?')
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] =='*')
                {
                    dp[i][j] = dp[i-1][j];
                    for(int k = 0;k<j;k++) dp[i][j] = dp[i][j] || dp[i][k];
                }
                else
                {
                    dp[i][j] =(dp[i-1][j-1] && p[i-1]==s[j-1]);
                }
            }
        }
        /*
        for(int i = 0;i<=p.size();i++)
        {
            for(int j = 0;j<=s.size();j++)
            {
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
        */
        return dp[p.size()][s.size()];
    }
};
