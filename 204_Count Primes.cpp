class Solution {
public:
    int countPrimes(int n) {
        bool *composite = new bool[n];
        memset(composite,false,sizeof(bool)*n);
        int count = 0;
        for(int i = 2;i<n;i++)
        {
            if(!composite[i])
            {
                count++;
                for(int j = i<<1;j<n;j+=i) composite[j] = true;
            }
        }
        return count;
    }
};
