import queue
class Solution:
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        q = queue.Queue() #visit queue
        al = [[] for i in range(numCourses)] #adjacency list
        indegree = [0]*numCourses #indegree of each vertex
        total = 0 #total number that has been visited
        #first record our graph
        for each in prerequisites: 
            indegree[each[0]]+=1
            al[each[1]].append(each[0])
        #put vertices with 0 indegree in queue
        for i in range(numCourses):
            if indegree[i]==0:
                q.put(i)
                total+=1
        #visit
        while not q.empty():
            cur = q.get()
            for each in al[cur]:
                indegree[each]-=1
                if indegree[each]==0:
                    q.put(each)
                    total+=1
        return total == numCourses
