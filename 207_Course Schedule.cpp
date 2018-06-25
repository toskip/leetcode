class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> temp;
        vector<vector<int> > adjlist(numCourses,temp);
        vector<int> indegree(numCourses,0);
        queue<int> ok;
        int len = prerequisites.size();
        for(int i = 0;i<len;i++)
        {
            adjlist[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }
        for(int i = 0;i<numCourses;i++)
        {
            if(!indegree[i]) ok.push(i);
        }
        int count = 0;
        while(!ok.empty())
        {
            count++;
            for(int i = 0;i<adjlist[ok.front()].size();i++)
            {
                indegree[adjlist[ok.front()][i]]--;
                if(!indegree[adjlist[ok.front()][i]]) ok.push(adjlist[ok.front()][i]);
            }
            ok.pop();
        }
        return count==numCourses;
    }
};
