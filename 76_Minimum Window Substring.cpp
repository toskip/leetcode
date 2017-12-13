//20171213总算独立做出一道hard，纪念一下
//击败10%
class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> dict;
        map<char,int> dict2;
        int n1 = s.size();
        int n2 = t.size();
        for(int i = 0;i<n2;i++) ++dict[t[i]];
        int left = 0;
        int count = 0;
        int len = n1;
        int start = -1;
        for(int i=0;i<n1;i++)
        {
            if(dict.count(s[i]))
            {
                if(dict2[s[i]]<dict[s[i]])
                {
                    ++count;
                }
                ++dict2[s[i]];
                if(count<n2) continue;
                while(!dict.count(s[left])||dict2[s[left]]>dict[s[left]])
                {
                    if(dict.count(s[left])) --dict2[s[left]];
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
        if(start==-1) return "";
        else return s.substr(start,len);
    }
};
