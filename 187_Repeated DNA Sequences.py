class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        n = len(s)
        hashtable = {}
        result = []
        for i in range(n-9):
            temp = s[i:i+10]
            if temp in hashtable and temp not in result:
                result.append(temp)
            else:
                hashtable[temp]=1
        return result
        
