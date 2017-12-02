//Greedy method in Solution#4
//this one is better.
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ok[30000] = {0};
        int firstgoodindex = nums.size()-1;
        ok[firstgoodindex] = 1; 
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(i+nums[i]>=firstgoodindex)
            {
                firstgoodindex = i;
                ok[i] =1;
            }
        }
        if(ok[0]) return true;
        else return false;
    }
};
