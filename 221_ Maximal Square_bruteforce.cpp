//挨个试
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n==0) return 0;
        int m = matrix[0].size();
        int result = 0;
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                bool found = false;
                int k = 0;
                for(k = 0;i+k<n &&j+k<m;k++)
                {
                    for(int p = 0;p<=k;p++)
                    {
                        if(matrix[i+p][j+k]=='0'||matrix[i+k][j+p]=='0')
                        {
                            found = true;
                            break;
                        }
                    }
                    if(found) break;
                }
                result = max(result,k*k);
            }
        }
        return result;
    }
};
