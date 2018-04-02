//这样好像明白一点
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int result = 0;
        for (int i=0;i<nums.size();i++)
        {
            int num = nums[i];
            if (m[num]) continue;
            m[num] = m[num-1]+m[num+1]+1;
            m[num+m[num+1]] = m[num];
            m[num-m[num-1]] = m[num];
            result = max(result,m[num]);
        }
        return result;
    }
};
