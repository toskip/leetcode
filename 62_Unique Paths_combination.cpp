//计算排列数，想办法避免溢出
//好吧 还是学了一下辗转相除法
class Solution {
public:
    int uniquePaths(int m, int n) {
        int small = min(m,n)-1;
        int sum = m+n-2;
        int beichushu = 1;
        int chushu = 1;
        int result = 1;
        for(int i=0;i<small;i++)
        {
            chushu*=i+1;
            int a = beichushu;
            int b = chushu;
            int r = a%b;
            while(r!=0)
            {
                a = b;
                b = r;
                r = a%b;
            }
            chushu/=b;
            beichushu/=b;
            beichushu*=sum-i;
            //cout<<beichushu<<' '<<chushu<<endl;
        }
        return beichushu/chushu;
    }
};
