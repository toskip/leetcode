class Solution:
    def wordBreak0(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        wordDict = set(wordDict)
        n = len(s)
        dp = [False]*(n+1)
        dp[0] = True
        for i in range(1,n+1):
            for j in range(i):
                if dp[j] and s[j:i] in wordDict:
                    dp[i] = True
                    break
        #print(dp)
        return dp[n]
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        self.wordDict = wordDict
        self.result = []
        self.cur = []
        if self.wordBreak0(s,wordDict):
            self.recur(s)
        return self.result
    
    def recur(self,s):
        if s=='':
            self.result.append(' '.join(self.cur))
        for i in range(1,len(s)+1):
            if s[:i] in self.wordDict:
                self.cur.append(s[:i])
                self.recur(s[i:])
                self.cur.pop()
                
                
        
        
        
