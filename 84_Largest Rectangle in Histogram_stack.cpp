class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        int result = 0;
        int top;
        int value;
        for(int i = 0;i<n;i++)
        {
            while(!st.empty() && heights[i]<heights[st.top()])
            {
                top = st.top();
                st.pop();
                value=st.empty()?-1:st.top();
                result = max(result,(i-1-value)*heights[top]);
            }
            st.push(i);
        }
        while(!st.empty())
        {
            top= st.top();
            st.pop();
            value=st.empty()?-1:st.top();
            result = max(result,(n-1-value)*heights[top]);
        }
        return result;
    }
};
