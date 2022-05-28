"""
https://leetcode.cn/contest/biweekly-contest-79/problems/booking-concert-tickets-in-groups/
两个线段树，一个存最大值，一个存区间和，以后类似的题可以直接拿来用
"""

class Tree:
    def __init__(self, nums):
        self.n = len(nums)
        self.d = [0] * 2 * self.n
        self.d1 = [0]*2*self.n
        for i in range(self.n, 2 * self.n):
            self.d[i] = nums[i - self.n]
            self.d1[i] = nums[i - self.n]
        i = self.n - 1
        while i > 0:
            self.d[i] = max(self.d[i * 2],self.d[i * 2 + 1])
            self.d1[i] = self.d1[i * 2]+self.d1[i * 2 + 1]
            i -= 1

    def update(self, pos, val):
        pos += self.n
        self.d[pos] = val
        self.d1[pos] = val
        pos//=2
        while pos>0:
            self.d[pos] = max(self.d[pos * 2],self.d[pos * 2 + 1])
            self.d1[pos] = self.d1[pos * 2]+self.d1[pos * 2 + 1]
            pos//=2

    def query(self, l, r):
        ans = 0
        ans2 = 0
        l += self.n
        r += self.n
        while l <= r:
            if l & 1:
                ans = max(ans,self.d[l])
                ans2+= self.d1[l]
                l += 1
            if not (r & 1):
                ans = max(ans, self.d[r])
                ans2+= self.d1[r]
                r -= 1
            l //= 2
            r //= 2
        return ans,ans2

    def getVal(self,pos):
        pos+=self.n
        return self.d[pos]

class BookMyShow:

    def __init__(self, n: int, m: int):
        self.n = n
        self.m = m
        self.t = Tree([m]*n)


    def gather(self, k: int, maxRow: int) -> List[int]:
        l = 0
        r = maxRow+1
        while l<r:
            mid = (l+r)>>1
            if self.t.query(0,mid)[0]>=k:
                r = mid
            else:
                l = mid+1
        if l<=maxRow:
            v = self.t.getVal(l)
            ans = [l,self.m-v]
            v-= k
            self.t.update(l,v)
            return ans
        else:
            return []



    def scatter(self, k: int, maxRow: int) -> bool:

        s = 0
        if self.t.query(0,maxRow)[1]<k:
            return False
        else:
            last = 0
            while k:
                l =last
                r = maxRow
                while l<r:
                    mid = (l+r)>>1
                    if self.t.query(0,mid)[1]>0:
                        r = mid
                    else:
                        l = mid+1
                v = self.t.getVal(l)
                mn = min(k,v)
                self.t.update(l,v-mn)
                k-=mn
            return True



# Your BookMyShow object will be instantiated and called as such:
# obj = BookMyShow(n, m)
# param_1 = obj.gather(k,maxRow)
# param_2 = obj.scatter(k,maxRow)
