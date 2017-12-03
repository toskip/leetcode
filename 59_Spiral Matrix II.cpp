//思路和第一个一样
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> temp(n);
        vector<vector<int>> result(n,temp);
        int max = n*n;
        int goodcount = 0;
        int count = 1;
        int i=0;
        int j = 0;
        int maxi =n;
        int maxj = n;
        int direction =0;
        int move[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        while(count<=max)
        {
            goodcount+=1;
            if(direction==0||direction==2)
            {
                if(goodcount==maxj)
                {
                    goodcount=0;
                    direction++;
                    maxi--;
                }
            }
            else
            {
                if(goodcount==maxi)
                {
                    goodcount=0;
                    direction = (direction+1)%4;
                    maxj--;
                }
            }
            result[i][j] = count;
            i+=move[direction][0];
            j+=move[direction][1];
            count++;
        }
        return result;
        
    }
};
