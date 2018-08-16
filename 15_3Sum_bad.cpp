
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int target = 0;
        unordered_map<int,int> hash;
        vector<vector<int> > result;
        for(int i  =0;i<n;i++)
        {
            hash[nums[i]] ++;
        }
        for(int i=0;i<n-2;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            target-=nums[i];
            hash[nums[i]]--;
            for(int j  = i+1;j<n-1;j++)
            {
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                target-=nums[j];
                hash[nums[j]]--;
                if(hash[target]>0 && target>=nums[j])
                {
                    //cout<<i<<' '<<j<<' '<<nums[i]<<' '<<nums[j]<<' '<<target<<' '<<hash[target]<<endl;
                    vector<int> temp(3,0);
                    temp[0] = nums[i];
                    temp[1] = nums[j];
                    temp[2] = target;
                    result.push_back(temp);
                    hash[nums[j]]++;
                    target+=nums[j];
                    continue;
                }
                hash[nums[j]]++;
                target+=nums[j];
            }
            hash[nums[i]]++;
            target+=nums[i];
        }
        return result;
    }
};
