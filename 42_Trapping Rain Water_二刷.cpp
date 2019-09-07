class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> left(size,0);
        vector<int> right(size,0);
        for(int i = 0;i<size;i++){
            left[i] = i==0?height[i]:max(left[i-1],height[i]);
            right[size-i-1] = i==0?height[size-1-i]:max(right[size-i],height[size-1-i]);
        }
        int result = 0;
        for(int i =0;i<size;i++){
            result+=min(left[i],right[i])-height[i];            
        }
        return result;
    }
};
