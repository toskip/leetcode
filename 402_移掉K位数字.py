class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        if k==len(num):
            return "0"
        result = int(num)
        #current = num
        for i in range(k):
            #num = current
            for j in range(len(num)):
                if j==len(num)-1 or num[j]>num[j+1]:
                    num = num[:j]+num[j+1:]
                    result = int(num)
                    break
        return str(result)
