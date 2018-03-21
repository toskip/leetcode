//思想和排列组合一样，优化了一下可以到O(k)了
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1,1);
        for(int i = 1 ;i<=rowIndex/2;i++)
        {
            result[i] = result[i-1]*((double)(rowIndex+1-i)/i)+0.5;//c语言的四舍五入orz
            result[rowIndex-i] = result[i];
        }
        return result;
    }
};
