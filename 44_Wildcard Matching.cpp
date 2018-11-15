//优化中
public:
    bool isMatch(string s, string p) {
        //vector<bool> temp(s.size()+1,0);
        //vector<vector<bool> > dp(p.size()+1,temp);
        bool** dp = new bool*[p.size()+1];
        for(int i = 0;i<=p.size();i++)
        {
            dp[i] = new bool[s.size()+1];
            //memset(dp[i],0,sizeof(bool)*(s.size()+1));
            fill(dp[i],dp[i]+(s.size()+1),0);
        }
        //fill(dp,dp+(s.size()+1)*(p.size()+1),0);
        dp[0][0] = 1;
        for(int i = 1;i<=p.size();i++)
        {
            if(p[i-1]=='?')
            {                
                for(int j = 1;j<=s.size();j++)
                {
                    dp[i][j] = dp[i-1][j-1];
                }
            }
            else if(p[i-1] =='*')
            {
                
                dp[i][0] = dp[i-1][0];
                for(int j = 1;j<=s.size();j++)
                {
                    dp[i][j] = dp[i-1][j];
                    for(int k = 0;k<j && dp[i][j]==0;k++)
                    {
                        dp[i][j] = dp[i][k];
                    }
                }
            } 
            else
            {                
                for(int j = 1;j<=s.size();j++)
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
