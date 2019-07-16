class Solution {
public:
    vector<vector<int>> result;
    vector<int> candidates;
    vector<int> current;
    int len;
    int k;
    int n;
    bool hash[10];
    vector<vector<int>> combinationSum3(int k, int n) {
        memset(hash,0,sizeof(hash));
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};
        this->candidates = candidates;
        this->k = k;
        this->n = n;
        len = candidates.size();
        dfs(0,n);
        return result;
    }
    void dfs(int start,int target)
    {
        for(int i = start;i<len;i++)
        {
            if(hash[candidates[i]]) continue;
            if(candidates[i]==target && current.size()==k-1)
            {
                current.push_back(candidates[i]);
                result.push_back(current);
                current.erase(current.end()-1);
                return;
            }
            else if(candidates[i]>target || current.size()>k-1)
            {
                return;
            }
            else
            {
                current.push_back(candidates[i]);
                hash[candidates[i]] = 1;
                dfs(i,target-candidates[i]);
                hash[candidates[i]] = 0;
                current.erase(current.end()-1);
            }
        }
    }
};
