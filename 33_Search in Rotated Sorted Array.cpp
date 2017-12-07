/*
二分查找
可以确定在右面的情况： target<low<mid low<mid<target mid<target<low
可以确定在左面的情况： target<mid<low mid<low<target low<target<mid
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[low]==target)
            {
                return low;
            }
            if(nums[mid]<nums[low])
            {
                if(target<nums[low] && target>nums[mid])
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            else
            {
                if(target<nums[mid] && target>nums[low])
                {
                    high= mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
        }
        return -1;
    }
};
