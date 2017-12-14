class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int sum = 0;
        int top;
        int distance;
        for(int i=0;i<height.size();i++)
        {
            while(!st.empty()&&height[st.top()]<height[i])
            {
                top = st.top();
                st.pop();
                if (st.empty()) break;
                distance = i-st.top()-1;
                
                sum+=(min(height[st.top()],height[i])-height[top])*distance;
            }
            st.push(i);
        }
        return sum;
    }
};
