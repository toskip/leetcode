//递归之前先看看里面每种字母个数是否相同
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
        int count[26]={};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }
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
