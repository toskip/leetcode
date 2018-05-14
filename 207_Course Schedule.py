import queue
class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        count = [0]*numCourses
        q = queue.Queue()
        al = [[] for i in range(numCourses)]
        total = 0
        for each in prerequisites:
            count[each[0]]+=1
            al[each[1]].append(each[0])
        for i in range(numCourses):
            if count[i]==0:
                q.put(i)
                total+=1
        while not q.empty():
            cur = q.get()
            for each in al[cur]:
                count[each]-=1
                if count[each]==0:
                    q.put(each)
                    total+=1
        return total == numCourses
