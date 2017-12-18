class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n==0) return 0;
        vector<int> dp(n+1,0);
        dp[0] =1;
        if(s[0]!='0') dp[1] = 1;
        int num;
        for(int i = 2;i<=n;i++)
        {
            if(s[i-1]!='0') dp[i]+=dp[i-1];
            if(s[i-2]!='0')
            {
                num = (s[i-2]-'0')*10+(s[i-1]-'0');
                if(num>=1 && num<=26) dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};
