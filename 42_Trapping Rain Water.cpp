//dp in solution#2
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0) return 0;
        int count = 0;
        int n = height.size()-1;
        int leftmax[11000];
        int rightmax[11000];
        rightmax[n] = height[n];
        leftmax[0] = height[0];
        for(int i=1;i<=n;i++)
        {
            leftmax[i] = max(leftmax[i-1],height[i]);
        }
        for(int i=n-1;i>=0;i--)
        {
            rightmax[i] = max(rightmax[i+1],height[i]);
        }
        for(int i=1;i<n;i++)
        {
            count+=min(leftmax[i],rightmax[i])-height[i];
        }
        return count;
    }
};
