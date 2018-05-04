//TLE 等会再改
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        return digui(s1,s2);
    }
    bool digui(string s1,string s2)
    {
        
        int len  =s1.size();
        //int len2 = s2.size();
        //int len = min(len1,len2);
        if(s1==s2)
        {
            //cout<<s1<<' '<<s2<<' '<<1<<endl;
            return true;
        }
        //cout<<s1<<' '<<s2<<endl;
        bool result = false;
        for(int i = 1; i<len;i++)
        {
            string s1left = s1.substr(0,i);
            string s1right = s1.substr(i,len-i);
            string s2left = s2.substr(0,i);
            string s2right = s2.substr(i,len-i);
            if((digui(s1left,s2left) && digui(s1right,s2right)))
            {
                result = true;
                break;
            }
            s2left = s2.substr(len-i,i);
            s2right = s2.substr(0,len-i);
            if((digui(s1left,s2left) && digui(s1right,s2right)))
            {
                result = true;
                break;
            }
        }
        //cout<<s1<<' '<<s2<<' '<<result<<endl;
        return result;
    }
};
