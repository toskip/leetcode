//遍历两遍
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {0,0,0};
        int i;
        for(i = 0;i<nums.size();i++)
        {
            count[nums[i]]++;
        }
        cout<<count[0]<<' '<<count[1]<<' '<<count[2]<<endl;
        for(i = 0;i<count[0];i++)
        {
            nums[i] = 0;
        }
        for(i = count[0];i<count[0]+count[1];i++)
        {
            nums[i] = 1;
        }
        for(i = count[0]+count[1];i<count[0]+count[1]+count[2];i++)
        {
            nums[i] = 2;
        }
    }
};
