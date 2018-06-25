class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> history;
        while(!history[n])
        {
            history[n] = true;
            int nextn = 0;
            while(n)
            {
                nextn+=(n%10)*(n%10);
                n/=10;
            }
            n = nextn;
        }
        return n==1;
            
    }
};
