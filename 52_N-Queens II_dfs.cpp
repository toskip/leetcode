//too slow
class Solution {
public:
    //vector<vector<string>> result;
    int count;
    vector<string> current;
    vector<bool> hashheng;
    vector<bool> hashshu;
    vector<bool> hashdui;
    vector<bool> hashfandui;
    int n;
    int remain;
    void dfs(int pos = 0)
    {
        if(remain==0)
        {
            //cout<<"found"<<endl;
            //result.push_back(current);
            count++;
            return;
        }
        int i = pos/n;
        int j = pos%n;
        while(i<n)
        {
            
                if(current[i][j]=='.' && hashheng[i]==0 && hashshu[j]==0 &&hashdui[j-i+n-1]==0 &&hashfandui[i+j]==0)
                {
                    //cout<<i<<' '<<j<<' '<<remain<<endl;
                    current[i][j] = 'Q';
                    hashheng[i] = 1;
                    hashshu[j] = 1;
                    hashdui[j-i+n-1] = 1;
                    hashfandui[i+j] = 1;
                    remain--;
                    dfs(i*n+j+1);
                    current[i][j] = '.';
                    hashheng[i] = 0;
                    hashshu[j] = 0;
                    hashdui[j-i+n-1] = 0;
                    hashfandui[i+j] = 0;
                    remain++;
                }
            j++;
            if(j==n)
            {
                j=0;
                i++;
            }
        }
    }
    int totalNQueens(int n) {
        count = 0;
        hashheng = vector<bool>(n,0);
        hashshu = vector<bool>(n,0);
        hashdui = vector<bool>(2*n-1,0);
        hashfandui = vector<bool>(2*n-1,0);
        string temp(n,'.');
        current = vector<string>(n,temp);
        this->n = n;
        remain = n;
        dfs();
        return count;
    }
};
