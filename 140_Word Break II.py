//递归，超时
class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        self.wordDict = wordDict
        self.result = []
        self.cur = []
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
                
                
        
        
        
