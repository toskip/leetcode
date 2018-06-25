class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> hashs;
        unordered_map<char,char> hasht;
        char curs = 'a';
        char curt = 'a';
        int n = s.size();
        for(int i = 0;i<n;i++)
        {
            if(!hashs[s[i]])
            {
                hashs[s[i]] = curs;
                s[i] = curs;
                curs++;
            }
            else
            {
                s[i] = hashs[s[i]];
            }
            if(!hasht[t[i]])
            {
                hasht[t[i]] = curt;
                t[i] = curt;
                curt++;
            }
            else
            {
                t[i] = hasht[t[i]];
            }
            if(s[i]!=t[i]) return false;
        }
        return true;
    }
};
