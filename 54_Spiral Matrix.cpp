//没啥好说的 到头就换方向
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size()==0) return result;
        int m = matrix.size();
        int n = matrix[0].size();
        
        //右0 下1 左2 上3
        int direction = 0;
        int move[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int i=0;
        int j=0;
        int imax = m;
        int jmax = n;
        int gocount = 0;
        int count = 0;
        int total = m*n;
        while(count<total)
        {
            //cout<<i<<' '<<j<<' '<<matrix[i][j]<<endl;
            result.push_back(matrix[i][j]);
            count++;
            gocount++;
            if(direction==0||direction==2)
            {
                if(gocount==jmax)
                {
                    gocount = 0;
                    direction++;
                    imax--;
                }
            }
            else
            {
                if(gocount==imax)
                {
                    gocount=0;
                    direction = (direction+1)%4;
                    jmax--;
                }
            }
            
            i+=move[direction][0];
            j+=move[direction][1];
            
        }
        return result;        
    }
};
