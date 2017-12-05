//有点慢
class Solution {
public:
    int mySqrt(int x) {
        for(int i =1;;i++)
        {
            if(i*i>x|| i*i<0) return i-1;
        }
    }
};
