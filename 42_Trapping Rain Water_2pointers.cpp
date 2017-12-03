//solution#4
//加速的黑科技
static vector<int> height=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return vector<int>{};
}();
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int count = 0;
        int left = 0;
        int right = height.size()-1;
        int leftmax = 0;
        int rightmax = 0;
        while(left<right)
        {
            if(height[left]<height[right])
            {
                if(height[left]>leftmax) leftmax = height[left];
                else count += leftmax-height[left];
                left++;
            }
            else  
            {
                if(height[right]>rightmax) rightmax = height[right];
                else count += rightmax-height[right];
                right--;
            }
        }
        return count;
    }
};
