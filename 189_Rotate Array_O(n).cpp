class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        gao(nums,0,nums.size(),k);
    }
    void gao(vector<int>& nums,int start,int n,int k)
    {
        if(n<=1) return;
        k %= n;
        if(k==0) return;
        for(int i = 0;i<k;i++) swap(nums[start+i],nums[start+n-k+i]);
        gao(nums,start+k,n-k,k);
    }
};
