class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int result = 0;
        int l=0;
        int r =height.size()-1;
        while(l!=r)
        {
            if(height[l]<height[r])
            {
                int temp = height[l]*(r-l);
                result=  max(result,temp);
                l++;
            }
            else
            {
                int temp = height[r]*(r-l);
                result=  max(result,temp);
                r--;                
            }
        }
        return result;
    }
};
