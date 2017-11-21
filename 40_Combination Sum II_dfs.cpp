class Solution {
public:
    vector<vector<int>> result;
    vector<int> candidates;
    vector<int> current;
    int len;
    int hash[35];
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        memset(hash,0,sizeof(hash));
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++)
        {
            hash[candidates[i]]++;
        }
        //candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        //resize is faster than erase
        candidates.resize(distance(candidates.begin(),unique(candidates.begin(),candidates.end())));
        this->candidates = candidates;
        len = candidates.size();
        dfs(0,target);
        return result;
    }
    void dfs(int start,int target)
    {
        for(int i = start;i<len;i++)
        {
            if(!hash[candidates[i]]) continue;
            if(candidates[i]==target)
            {
                current.push_back(candidates[i]);
                result.push_back(current);
                current.erase(current.end()-1);
                return;
            }
            else if(candidates[i]>target)
            {
                return;
            }
            else
            {
                current.push_back(candidates[i]);
                hash[candidates[i]]--;
                dfs(i,target-candidates[i]);
                current.erase(current.end()-1);
                hash[candidates[i]]++;
            }
        }
    }
};
