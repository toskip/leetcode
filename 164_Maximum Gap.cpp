class Solution {
public:
    void radixsort(vector<int>& nums)
    {
        int n = nums.size();
        int maxvalue = *max_element(nums.begin(),nums.end());
        int base = 10;
        for(int radix =1;radix<=maxvalue;radix*=base)
        {
            vector<int> temp(n,0);
            vector<int> count(base+1,0);
            for(int i = 0;i<n;i++)
            {
                count[(nums[i]/radix)%base+1]++;
            }
            for(int i =1;i<=base;i++)
            {
                count[i]+=count[i-1];
            }
            for(int i = 0;i<n;i++)
            {
                temp[count[(nums[i]/radix)%base]++] = nums[i];
            }
            nums = temp;
        }
    }
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        int result = 0;
        /*
            sort(nums.begin(),nums.end());
        */
        radixsort(nums);
        for(int i =1;i<n;i++)
        {
            result = max(result,nums[i]-nums[i-1]);
        }
        return result;
    }
};
