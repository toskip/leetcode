class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        bool minus = false;
        int i = 0;
        int n  = str.size();
        while(str[i]==' ') i++;
        if(str[i]=='-')
        {
            i++;
            minus = true;
        }
        else if(str[i]=='+')
        {
            i++;
        }
        for(;i<n;i++)
        {
            if(!isdigit(str[i])) break;
            int next = result*10+(str[i]-'0');
            if(next/10!=result)
            {
                //overflow
                if(minus) return INT_MIN;
                else return INT_MAX;
            }
            result =  next;
        }
        if(minus) result = - result;
        return result;
    }
};
