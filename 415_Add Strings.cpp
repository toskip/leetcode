class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int i = n1-1;
        int j = n2-1;
        int val;
        bool jinwei = 0;
        string result="";
        while(i>=0||j>=0)
        {
            val = (i>=0?num1[i]-'0':0)+(j>=0?num2[j]-'0':0)+jinwei;
            result = (char)((val%10)+'0')+result;
            jinwei = val/10;
            if(i>=0) i--;
            if(j>=0) j--;
        }
        if(jinwei) result = '1'+result;
        return result;
    }
};
