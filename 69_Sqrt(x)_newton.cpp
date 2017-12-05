//解释：https://www.guokr.com/question/461510/
class Solution {
public:
    int mySqrt(int x) {    
        long r = x;
        while (r*r > x)
            r = (r + x/r) / 2;
        return r;
    }
};
