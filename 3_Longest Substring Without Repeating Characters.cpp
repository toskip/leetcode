//dp方法，O(n)
int indices[128];
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int* dp = new int[n];
        memset(dp,0,sizeof(dp));
        memset(indices,-1,sizeof(indices));
        dp[0] = 1;
        indices[s[0]] = 0;
        int startindex = 0;
        for(int i = 1;i<n;i++)
        {
            if(indices[s[i]]>=startindex)
            {
                startindex = indices[s[i]]+1;
                dp[i] = dp[i-1];
            }
            else dp[i] = max(dp[i-1],i-startindex+1);
            indices[s[i]] =i;
        }
        return dp[n-1];
    }
};
