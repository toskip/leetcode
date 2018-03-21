//排列组合，时间复杂度不符合要求
class Solution {
public:
    int combination(int n,int m)
    {
        //计算组合数
        double result = 1;
        for(int i = 0;i<m;i++) result*=(double)(n-i)/(m-i);
        return result+0.5;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,1);
        for(int i = 1 ;i<=rowIndex/2;i++)
        {
            result[i] = combination(rowIndex,i);
            result[rowIndex-i] = result[i];
        }
        return result;
    }
};
