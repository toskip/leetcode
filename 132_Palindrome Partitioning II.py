#dp
class Solution:
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        pal = [[False for i in range(n)] for i in range(n)]
        dp =[sys.maxsize]*n
        for i in range(n):
            for j in range(n-i):
                if s[j]==s[j+i] and(i<=1 or pal[j+1][j+i-1]):
                    pal[j][j+i] = True
        #print(pal)
        dp[n-1] = 0
        for i in range(n-2,-1,-1):
            if pal[i][n-1]:
                dp[i] = 0
            else:
                for j in range(n-2,i-1,-1):
                    if pal[i][j]:
                        dp[i] = min(dp[i],dp[j+1]+1)
        #print(dp)
        return dp[0]
