//TLE
//当然でしょう
int mymove[2][2] = {{0,1},{1,0}};
class Solution {
public:
    int count;
    int m;
    int n;
    void dfs(int i,int j)
    {
        if(i==m && j==n)
        {
            count++;
            return;
        }
        for(int direction = 0;direction<=1;direction++)
        {
            if(i+mymove[direction][0]<=m &&j+mymove[direction][1]<=n)
            {
                dfs(i+mymove[direction][0],j+mymove[direction][1]);
            }
        }
    }
    int uniquePaths(int m, int n) {
        count = 0;
        this->m = m-1;
        this->n = n-1;
        dfs(0,0);
        return count;
    }
};
