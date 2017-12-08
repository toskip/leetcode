//好吧原来不需要dp，太蠢了
//记录下每个字符最后一次出现的位置与当前子序列的开始
//O(n)
int indices[128];
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        memset(indices,-1,sizeof(indices));
        int n = s.size();
        int maxlen = 0;
        int startindex = 0;
        for(int i = 0;i<n;i++)
        {
            if(indices[s[i]]>=startindex) startindex = indices[s[i]]+1;
            else maxlen = max(maxlen,i-startindex+1);
            indices[s[i]] =i;
        }
        return maxlen;
    }
};
