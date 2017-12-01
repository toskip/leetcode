//still backtrack
#define MAX 20
#define HALF MAX/2
class Solution {
public:
    vector<int> nums;
    vector<vector<int>> result;
    vector<int> current;
    int hash[MAX];
    void dfs()
    {
        bool finish = true;
        for(int i=0;i<nums.size();i++)
        {
            if(hash[HALF+nums[i]]==0) continue;
            finish = false;
            current.push_back(nums[i]);
            hash[HALF+nums[i]] --;
            dfs();
            hash[HALF+nums[i]] ++;
            current.pop_back();
        }
        if(finish)
        {
            result.push_back(current);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        memset(hash,0,sizeof(hash));
        for(int i=0;i<nums.size();i++)
        {
            hash[HALF+nums[i]]++;
            this->nums.push_back(nums[i]);
        }
        sort(this->nums.begin(),this->nums.end());
        this->nums.resize(distance(this->nums.begin(),unique(this->nums.begin(),this->nums.end())));
        dfs();
        return result;
    }
};
