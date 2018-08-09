class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int n = s.size();
        bool** dp = new bool*[n];
        //vector<bool> temp(n,0);
        //vector<vector<bool>> dp(n,temp);
        int length = 1;
        int start = 0;
        for(int i =0;i<n;i++)
        {
            dp[i] = new bool[n];
            fill(dp[i],dp[i]+n,0);
            dp[i][i] = 1;
            if(i<n-1 && s[i]==s[i+1])
            {
                dp[i][i+1] = 1;
                if(length<2)
                {
                    length = 2;
                    start = i;
                }
            }
        }
        for(int step = 2;step<n;step++)
        {
            for(int i = 0;i+step<n;i++)
            {
                dp[i][i+step] = (s[i]==s[i+step]&&dp[i+1][i+step-1]);
                if(dp[i][i+step]&&length<step+1)
                {
                    
                    length = step+1;
                    start = i;
                }
            }
        }
        /*
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
                cout<<dp[i][j]<<' ';
            cout<<endl;
        }
        */
        for(int i = 0;i<n;i++) delete dp[i];
        delete dp;
        return s.substr(start,length);
        
    }
};
