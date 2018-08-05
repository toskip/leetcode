class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<int> max1(m,0);
        vector<int> max2(n,0);
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]>0) count++;
                max1[i] = max(max1[i],grid[i][j]);
                max2[j] = max(max2[j],grid[i][j]);
            }
        }
        for(int i = 0;i<m;i++) count+=max1[i];
        for(int i = 0;i<n;i++) count+=max2[i];
        return count;
    }
};
