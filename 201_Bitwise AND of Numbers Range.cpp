//位运算 多么优雅
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m==0) return 0;
        bitset<33> temp(m);
        int i = 0;
        while(i<33)
        {
            if(temp[i]==0)
            {
                i++;
                continue;
            }
            while(temp[i]==1 && i<33) 
            {
                temp[i] = 0;
                i++;
                
            }
            temp[i] = 1;
            unsigned int current = temp.to_ulong();
            if(current>n) break;
            m&=current;
        }
        return m;
    }
};
