class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        int result = INT_MAX;
        while(low<=high)
        {
            mid = (low+high)/2;
            result = min(result,nums[mid]);
            if(low==high) break;
            if(nums[mid]>nums[high])
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
            
        }
        return result;
        
    }
};
