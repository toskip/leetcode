//最普通的
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string,int> hash;
        int count = 0;
        for(int i=0;i<strs.size();i++)
        {
            int sum = 0;
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            if(hash.find(temp)==hash.end())
            {
                //meizhaodao
                hash[temp]=count++;
                vector<string> current;
                current.push_back(strs[i]);
                result.push_back(current);
            }
            else
            {
                result[hash[temp]].push_back(strs[i]);
            }
        }
        return result;
    }
};
