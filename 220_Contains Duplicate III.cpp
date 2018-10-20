class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        map<int,int> haxi;
        if(t<=n/2)
        {
            for(int i =0;i<n;i++)
            {
                for(int j = -t;j<=t;j++)
                {
                    if(haxi.count(nums[i]+j) && i-haxi[nums[i]+j]<=k)
                    {
                        return true;
                    }
                }
                haxi[nums[i]] = i;
            }
            return false;
        }
        else
        {
            for(int i = 0;i<n;i++)
            {
                for(int j = i+1;j<n;j++)
                {
                    if(j-i<=k && abs((long long)nums[j]-(long long)nums[i])<=t)
                        return true;
                }
            }
            return false;
        }
    }
};
