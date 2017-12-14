class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> dict;
        int n1 = s.size();
        int n2 = t.size();
        for(int i = 0;i<n2;++i) ++dict[t[i]];
        int left = 0;
        int count = 0;
        int len = n1;
        int start = -1;
        for(int i=0;i<n1;++i)
        {
            if(dict.count(s[i]))
            {
                if(dict[s[i]]>0) ++count;
                --dict[s[i]];
                if(count<n2) continue;
                while(!dict.count(s[left])||dict[s[left]]<0)
                {
                    if(dict.count(s[left])) ++dict[s[left]];
                    ++left;
                }
                if(count==n2 && i-left+1<=len)
                {
                    len = i-left+1;
                    start = left;
                }
            }
        }
        if(start==-1) return "";
        else return s.substr(start,len);
    }
};
