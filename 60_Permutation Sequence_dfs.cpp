//dfs打表
bool ok = false;
vector<string> nums[10];
class Solution {
public:
    bool hash[10];
    string current;
    void dfs(int n)
    {
        if(current.size()==n)
        {
            nums[n].push_back(current);
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(hash[i]==0)
                {
                    hash[i] = 1;
                    current+=('0'+i);
                    dfs(n);
                    hash[i] = 0;
                    current.pop_back();
                }
            }
        }
    }
    string getPermutation(int n, int k) {
        if(ok) return nums[n][k-1];
        else
        {
            memset(hash,0,sizeof(hash));
            for(int i=1;i<=9;i++)
            {
                dfs(i);
            }
            ok = true;
            return nums[n][k-1];
        }
    }
};
