//击败了3%..rnmb
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> hash;
        int count = 1;
        for(int i=0;i<strs.size();i++)
        {
            int sum = 0;
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            int index = -1;
            for(int j=0;j<hash.size();j++)
            {
                if(hash[j]==temp)
                {
                    index = j;
                    break;
                }
            }
            if(index ==-1)
            {
                hash.push_back(temp);
                vector<string> current;
                current.push_back(strs[i]);
                result.push_back(current);
            }
            else
            {
                result[index].push_back(strs[i]);
            }
        }
        return result;
    }
};
