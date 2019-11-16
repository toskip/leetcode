class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        char test[26] = {0};
        for(int i = 0;i<s.size();i++){
            test[s[i]-'a']++;
            test[t[i]-'a']--;
        }
        for(int i = 0;i<26;i++){
            if(test[i]) return false;
        }
        return true;
    }
};
