//O(n)方法，速度最快
//写的太蠢了 以后再想怎么写的好看一点
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> nums(n+1);
        int jiecheng = 1;
        for(int i =0;i<n;i++)
        {
            nums[i] = '1'+i;
            jiecheng*=(i+1);
        }
        string result(n,'0');
        int current = k-1;
        for(int i=n;i>1;i--)
        {
            jiecheng/=i;
            int index = current/jiecheng;
            result[n-i]= nums[index];
            nums.erase(nums.begin()+index);//这个是关键
            current%=jiecheng;
        }
        result[n-1] = nums[0];
        return result;
    }
};
