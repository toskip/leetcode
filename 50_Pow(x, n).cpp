//mdzz
class Solution {
public:
    double myPow(double x, int n) {
        if(x==1) return 1;
        if(x==-1)
        {
            if(n%2==0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        if(n==INT_MIN) return 0;
        double result=1;
        if(n<0)
        {
            x = 1/x;
            n =-n;
        }
        for(int i=0;i<n;i++)
        {
            result*=x;
            if(result==0) return 0;
        }
        return result;
    }
};
