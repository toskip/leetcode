//too slow
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        map<string,int> haxi;
        map<string,int> haxi2;
        int n = s.size();
        int p = words.size();
        int q = words[0].size();
        for(int i = 0;i<p;i++) ++haxi[words[i]];
        for(int i = 0;i<n;i++)
        {
            haxi2 = haxi;
            bool ok = true;
            for(int j = 0;j<p;j++)
            {
                string temp = s.substr(i+j*q,q);
                if(haxi2[temp]) --haxi2[temp];
                else
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
