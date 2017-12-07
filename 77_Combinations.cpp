class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;
    int n,k;
    void dfs(int start,int numbers)
    {
        if(numbers==k)
        {
            result.push_back(current);
            return;
        }
        for(int i = start;i<=n;i++)
        {
                current.push_back(i);
                dfs(i+1,numbers+1);
                current.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        dfs(1,0);
        return result;
    }
};
