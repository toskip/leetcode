//直接套了31题，应该有简单办法
class Solution {
public:
    void nextPermutation(string& nums) 
    {
        //if(nums.size()==1) return;
        int i = nums.size()-2;
        for(;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                break;
            }
        }
        if(i!=-1)
        {
            for(int j = nums.size()-1;j>i;j--)
            {
                if(nums[j]>nums[i])
                {
                    int temp = nums[j];
                    nums[j] = nums[i];
                    nums[i] = temp;
                    break;
                }
            }
        }
        reverse(nums.begin()+i+1,nums.end());
    }    
    string getPermutation(int n, int k) {
        string nums = "";
        for(int i=1;i<=n;i++)
        {
            nums+= (i+'0');
        }
        for(int i=1;i<k;i++)
        {
            nextPermutation(nums);
        }
        return nums;
    }
};
