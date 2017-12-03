//关键是确定每一行只能并且一定要放一个queen。明确了这一点之后时间从144ms优化到3ms
class Solution {
public:
    vector<vector<string>> result;
    vector<string> current;
    vector<bool> hashheng;
    vector<bool> hashshu;
    vector<bool> hashdui;
    vector<bool> hashfandui;
    int n;
    int remain;
    void dfs(int i)
    {
        if(remain==0)
        {
            result.push_back(current);
            return;
        }
        int j = 0;
        while(j<n)
        {
                if(hashheng[i]==0 && hashshu[j]==0 &&hashdui[j-i+n-1]==0 &&hashfandui[i+j]==0)
                {
                    current[i][j] = 'Q';
                    hashheng[i] = 1;
                    hashshu[j] = 1;
                    hashdui[j-i+n-1] = 1;
                    hashfandui[i+j] = 1;
                    remain--;
                    dfs(i+1);
                    current[i][j] = '.';
                    hashheng[i] = 0;
                    hashshu[j] = 0;
                    hashdui[j-i+n-1] = 0;
                    hashfandui[i+j] = 0;
                    remain++;
                }
            j++;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        hashheng = vector<bool>(n,0);
        hashshu = vector<bool>(n,0);
        hashdui = vector<bool>(2*n-1,0);
        hashfandui = vector<bool>(2*n-1,0);
        string temp(n,'.');
        current = vector<string>(n,temp);
        this->n = n;
        remain = n;
        dfs(0);
        return result;
    }
};
