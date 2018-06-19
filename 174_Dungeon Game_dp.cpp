//自己a出来的 超有成就感~~
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<int> temp(m,0);
        vector<vector<int> > dp(n,temp);
        dp[n-1][m-1] = dungeon[n-1][m-1];
        for(int i =n-2;i>=0;i--)
        {
            if(dungeon[i][m-1]<0 && dp[i+1][m-1]>0)dp[i][m-1] = dungeon[i][m-1];
            else dp[i][m-1] = dp[i+1][m-1]+dungeon[i][m-1];
        }
        for(int j = m-2;j>=0;j--)
        {
            if(dungeon[n-1][j]<0 && dp[n-1][j+1]>0)dp[n-1][j] = dungeon[n-1][j];
            else dp[n-1][j] = dp[n-1][j+1]+dungeon[n-1][j];
        }
        for(int i =n-2;i>=0;i--)
        {
            for(int j = m-2;j>=0;j--)
            {
                int down,right;
                if(dungeon[i][j]<0 && dp[i+1][j]>0) down =dungeon[i][j];
                else down = dp[i+1][j]+dungeon[i][j];
                if(dungeon[i][j]<0 && dp[i][j+1]>0) right = dungeon[i][j];
                else right = dp[i][j+1]+dungeon[i][j];
                dp[i][j] = max(down,right);
            }
        }
        /*
        Debug用
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                cout<<dp[i][j]<<' ';
            }
            cout<<endl;
        }
        */
        return max(0,-dp[0][0])+1;
    }
};
