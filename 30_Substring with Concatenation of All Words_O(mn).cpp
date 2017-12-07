//O(mn)
//not good
class Solution {
public:
    vector<string> possible;
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        map<string,int> hash;
        for(int i=0;i<words.size();i++)
        {
            if(hash.count(words[i]))
            {
                hash[words[i]]++;
            }
            else
            {
                hash[words[i]] = 1;
            }
        }
        int window = words.size()*words[0].size();
        int lens = s.size();
        for(int i=0;i<=lens-window;i++)
        {
            bool ok = true;
            map<string,int> hash2 = hash;
            for(int j = i;j<i+window;j+=words[0].size())
            {
                string current = s.substr(j,words[0].size());
                if(hash2[current])
                {
                    hash2[current]--;
                }
                else
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                bool ok2 = true;
                for(int j=0;j<words.size();j++)
                {
                    if(hash2[words[j]])
                    {
                        ok2 =false;
                        break;
                    }
                }
                if(ok2)
                {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};
