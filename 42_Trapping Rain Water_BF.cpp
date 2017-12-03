//brute force in solution#1
class Solution {
public:
    int trap(vector<int>& height) {
        int count = 0;
        int n = height.size()-1;
        for(int i=1;i<n;i++)
        {
            int leftmax = 0;
            for(int j =i;j>=0;j--)
            {
                if(height[j]>leftmax) leftmax = height[j];
            }
            int rightmax = 0;
            for(int j = i;j<=n;j++)
            {
                if(height[j]>rightmax) rightmax = height[j];
            }
            count+=min(leftmax,rightmax)-height[i];
        }
        return count;
    }
};
