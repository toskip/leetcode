class Solution {
public:
    bool isPowerOfTwo(int n) {
        int m = 1;
        while(m>0){
            if(m==n) return true;
            if(m>n) return false;
            m<<=1;
        }
        return false;
    }
};
