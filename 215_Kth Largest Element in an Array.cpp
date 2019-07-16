class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> a; 
        for(int i = 0;i<nums.size();i++){
            a.push(nums[i]);
        }
        while(--k){
            a.pop();
        }
        return a.top();
    }
};
