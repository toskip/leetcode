class Solution {
public:
    vector<vector<int>> result;
    vector<int> candidates;
    vector<int> current;
    int len;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        this->candidates = candidates;
        len = candidates.size();
        dfs(0,target);
        return result;
    }
    void dfs(int start,int target)
    {
        for(int i = start;i<len;i++)
        {
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
                dfs(i,target-candidates[i]);
                current.erase(current.end()-1);
                
            }
        }
    }
};
