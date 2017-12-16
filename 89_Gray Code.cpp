//格雷码与二进制的转换
//blog.csdn.net/jingfengvae/article/details/51691124
class Solution {
public:
    int convert(int x)
    {
        return x^(x>>1);
    }
    vector<int> grayCode(int n) {
        int number = pow(2,n);
        vector<int> result(number,0);
        for(int i = 0;i<number;i++)
        {
            result[i] = convert(i);
        }
        return result;
    }
};
