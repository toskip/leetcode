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
        total = 0
        for each in prerequisites:
            count[each[1]]+=1
        for i in range(numCourses):
            if count[i]==0:
                q.put(i)
                total+=1
        while not q.empty():
            cur = q.get()
            for each in prerequisites:
                if each[0]==cur:
                    count[each[1]]-=1
                    if count[each[1]]==0:
                        q.put(each[1])
                        total+=1
        if total == numCourses: return True
        else: return False
            
