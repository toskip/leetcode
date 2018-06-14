//dp,O(n)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n  = nums.size();
        int* dpmax = new int[n];
        int* dpmin = new int[n];
        dpmax[0] = nums[0];
        dpmin[0] = nums[0];
        int result = dpmax[0];
        for(int i = 1;i<n;i++)
        {
            dpmax[i] = max(max(dpmax[i-1]*nums[i],dpmin[i-1]*nums[i]),nums[i]);
            dpmin[i] = min(min(dpmax[i-1]*nums[i],dpmin[i-1]*nums[i]),nums[i]);
            result = max(result,dpmax[i]);
        }
        return result;
    }
};
