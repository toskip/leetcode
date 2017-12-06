//先记下第一行和第一列是否归0，然后从开始遍历除第一行和第一列的所有元素，如果遇到0，把本行第一个元素和本列第一个元素归0
//之后遍历第一列除(0,0)之外的元素，遇到0把整行归0
//之后遍历第一行除(0,0)之外的元素，遇到0把整列归0
//最后根据最开始记下的结果决定第一行和第一列是否归0
//时间复杂度O(mn+3m+3n)
//空间复杂度O(1)
//by myself
class Solution {
public:
    int m;
    int n;
    void setZeroes(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        bool row0is0 = false;
        bool col0is0 = false;
        for(int i=0;i<m;i++)
        {
            if(!matrix[i][0])
            {
                col0is0 = true;
                break;
            }
        }        
        for(int j=0;j<n;j++)
        {
            if(!matrix[0][j])
            {
                row0is0 = true;
                break;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1;i<m;i++)
        {
            if(!matrix[i][0])
            {
                for(int j = 1;j<n;j++)
                    matrix[i][j] = 0;
            }
        }
        for(int  j =1;j<n;j++)
        {
            if(!matrix[0][j])
            {
                for(int i =1;i<m;i++)
                    matrix[i][j] = 0;
            }
        }
        if(col0is0)
        {
            for(int i=0;i<m;i++) matrix[i][0] = 0;
        }
        if(row0is0)
        {
            for(int j = 0;j<n;j++) matrix[0][j] = 0;
        }
        /*
        for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                cout<<matrix[i][j]<<' ';
            }
            cout<<endl;
        }
        */
    }
};
