class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s = s.split(' ')
        s.reverse()
        s = [each for each in s if each!='']
        return ' '.join(s)
        
