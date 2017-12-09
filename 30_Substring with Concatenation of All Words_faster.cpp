//64%
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string,int> haxi;
        unordered_map<string,int> haxi2;
        int n = s.size();
        int p = words.size();
        int q = words[0].size();
        int max = n-q;
        int max2 = n-p*q;
        string* subs = new string[max+1];
        for(int i = 0;i<=max;i++) subs[i] = s.substr(i,q);
        for(int i = 0;i<p;i++) ++haxi[words[i]];
        for(int i = 0;i<=max2;++i)
        {
            haxi2.clear();
            bool ok = true;
            for(int j = i;j<i+p*q;j+=q)
            {
                if(++haxi2[subs[j]]>haxi[subs[j]])
                {
                    ok = false;
                    break;
                }
            }
            if(ok) result.push_back(i); 
        }
        return result;
    }
};
