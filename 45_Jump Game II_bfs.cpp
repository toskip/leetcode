//easy solution, thanks for discuss#1
class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0;
        int end = 0;
        int nextend = 0;
        int level = 0;
        while(end<nums.size()-1)
        {
            for(int i=start;i<=end;i++)
            {
                nextend = max(nextend,i+nums[i]);
            }
            start = end+1;
            end = nextend;
            level++;
        }
        return level;
    }
};
