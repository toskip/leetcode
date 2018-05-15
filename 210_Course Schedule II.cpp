class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        queue<int> q;
        vector<int> temp;
        vector<vector<int> > al(numCourses,temp);
        vector<int> count(numCourses,0);
        int total = 0;
        vector<int> result(numCourses,0);
        for(int i = 0;i<prerequisites.size();i++)
        {
            al[prerequisites[i].second].push_back(prerequisites[i].first);
            count[prerequisites[i].first]++;
        }
        for(int i = 0;i<numCourses;i++)
        {
            if(!count[i])
            {
                result[total++] = i;
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
                    result[total++] = al[cur][i];
                    q.push(al[cur][i]);
                }
            }
        }
        if(total!=numCourses) result.clear();
        return result;
    }
};
