#TLE了，下午接着改，优化一下不难
class Solution:
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        n = len(ratings)
        give = [0]*n
        give[0] =1
        for i in range(1,n):
            if ratings[i]>ratings[i-1]:
                give[i] = give[i-1]+1
            else:
                give[i] =1
                j = i
                while j>0 and ratings[j-1]>ratings[j] and give[j-1]==give[j]:
                    give[j-1]+=1
                    j-=1
        result = 0
        #print(give)
        for i in range(n):
            result+=give[i]
        return result
