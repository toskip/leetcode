//TLE 等会再改
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        return digui(s1,s2);
    }
    bool digui(string s1,string s2)
    {
        if(s1==s2)
            return true;
        int len  =s1.size();
        bool result = false;
        for(int i = 1; i<len;i++)
        {
            if(digui(s1.substr(0,i),s2.substr(0,i)) && digui(s1.substr(i),s2.substr(i)))
                return true;
            if(digui(s1.substr(0,i),s2.substr(len-i)) && digui(s1.substr(i),s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};
