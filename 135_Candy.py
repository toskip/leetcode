#想了半天 应该是最优解法了
#代码和思路都很elegent，超有成就感有木有
class Solution:
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n = len(ratings)
        increase = [1]*n
        decrease = [1]*n
        for i in range(1,n):
            if ratings[i]>ratings[i-1]: increase[i] = increase[i-1]+1
            if ratings[n-i-1]>ratings[n-i]: decrease[n-1-i] = decrease[n-i]+1
        result = 0
        for i in range(n):
            result += max(increase[i],decrease[i])
        return result
