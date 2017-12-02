//too slow ,try dp instead
class Solution {
public:
    int last;
    vector<int> nums;
    bool finish;
    bool hash[30000];
    void dfs(int pos)
    {
        if(pos==last) finish = true;
        if(finish) return ;
        for(int i = nums[pos];i>0 ;i--)
        {
            //cout<<pos<<' '<<i<<endl;
            if(pos+i>last) continue;
            if(hash[pos+i]) continue;
            hash[pos+i] = 1;
            dfs(pos+i);
            if(finish) return;
        }
    }
    bool canJump(vector<int>& nums) {
        memset(hash,0,sizeof(hash));
        last = nums.size()-1;
        finish = false;
        for(int i=0;i<nums.size();i++)
        {
            this->nums.push_back(nums[i]);
        }
        dfs(0);
        return finish;
    }
};
