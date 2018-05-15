class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        queue<int> q;
        vector<int> temp;
        vector<vector<int> > al(numCourses,temp);
        vector<int> count(numCourses,0);
        int total = 0;
        for(int i = 0;i<prerequisites.size();i++)
        {
            al[prerequisites[i].first].push_back(prerequisites[i].second);
            count[prerequisites[i].second]++;
        }
        for(int i = 0;i<numCourses;i++)
        {
            if(!count[i])
            {
                total++;
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            for(int i = 0;i<al[cur].size();i++)
            {
                if(!--count[al[cur][i]])
                {
                    total++;
                    q.push(al[cur][i]);
                }
            }
        }
        return total == numCourses;
    }
};
