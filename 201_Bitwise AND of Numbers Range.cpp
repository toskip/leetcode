//位运算 多么优雅
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        bitset<32> temp(m);
        int i = 0;
        unsigned int current;
        for(int i = 0;i<32;)
        {
            if(temp[i]==0)
            {
                i++;
                continue;
            }
            while(temp[i]==1) 
            {
                temp[i] = 0;
                i++;
                
            }
            temp[i] = 1;
            current = temp.to_ulong();
            if(current>n) break;
            m&=current;
        }
        return m;
    }
};

/*
//标准答案的方法
class Solution {
public:
    long long rangeBitwiseAnd(int m, int n) {        
        int cnt = 0;

        while(n != 0 && m != 0) {
            if (n == m) {
                long long r = n;

                return (r << cnt);
            }
            
            n /= 2;
            m /= 2;
            cnt+=1;
        }
        
        
        return 0;
    }
};
*/
