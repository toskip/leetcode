//击败80%-90%
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
        string* subs = new string[max+1];
        for(int i = 0;i<=max;++i) subs[i] = s.substr(i,q);
        for(int i = 0;i<p;++i) ++haxi[words[i]];
        for(int i = 0;i<q;++i)
        {
            haxi2.clear();
            int left = i;
            for(int j = i;j<=max;j+=q)
            {
                if(haxi.count(subs[j]))
                {
                    if(++haxi2[subs[j]]>haxi[subs[j]])
                    {
                        while(haxi2[subs[j]]>haxi[subs[j]])
                        {
                            --haxi2[subs[left]];
                            left+=q;
                        }
                    }
                    else if(j-left==(p-1)*q)
                    {
                        result.push_back(left);
                        --haxi2[subs[left]];
                        left+=q;
                    }
                }
                else
                {
                    haxi2.clear();
                    left=j+q;
                }
            }
        }
        return result;
    }
};
