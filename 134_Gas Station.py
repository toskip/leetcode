class Solution:
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        n = len(gas)
        leiji = [0]*n
        leiji[0] = gas[0]-cost[0]
        minvalue = leiji[0]
        minpos = 0
        for i in range(1,n):
            leiji[i] = gas[i]-cost[i]+leiji[i-1]
            if leiji[i]<minvalue:
                minvalue = leiji[i]
                minpos = i
        if leiji[-1]<0: return -1
        else: return 0 if minpos==n-1 else minpos+1
