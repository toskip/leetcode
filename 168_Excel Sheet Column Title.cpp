class Solution {
public:
    string convertToTitle(int n) {
        string s="";
        while(n)
        {
            int temp = n%26;
            if(!temp) temp=26;
            s+='@'+temp;
            n = (n-temp)/26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
