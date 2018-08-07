class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n  = s.size();
        int size = 0;//滑动窗口大小
        unordered_map<char,bool> dict;
        int result = 0;
        for(int i = 0;i<n;i++)
        {
            while(dict[s[i]])
            {
                dict[s[i-size]] = 0;
                size--;
            }
            dict[s[i]] = 1;
            size++;
            result = max(result,size);
        }
        return result;
        
    }
};
