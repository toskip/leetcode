#我TM终于受不了c++改用python了
class Solution:
    def partition(self, s):
        self.result = []
        self.cur = []
        self.recur(s)
        return self.result
    def recur(self,s):
        if s=='':
            self.result.append(copy.copy(self.cur))
            return
        for i in range(len(s)):
            temp = s[:i+1]
            if temp[::-1]==temp:
                self.cur.append(temp)
                self.recur(s[i+1:])
                self.cur.pop()
