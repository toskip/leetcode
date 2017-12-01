//水题 没啥可说的
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int n1 = n/2;
        for(int i = 0;i<n1;i++)
        {
            
            int n2 = n-i-1;
            //含义是减掉左边已经置换过的几个和右上角那一个
            for(int j = i;j<n2;j++)
            {
                
                
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
            }
        }
    }
};
