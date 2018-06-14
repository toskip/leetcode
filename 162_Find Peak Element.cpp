class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int n = nums.size();
        int high = n-1;
        int mid;
        stack<pair<int,int> > st;
        st.push(make_pair(low,high));
        while(!st.empty())
        {
            low = st.top().first;
            high = st.top().second;
            st.pop();
            mid = low+(high-low)/2;
            //cout<<nums[mid]<<endl;
            if((mid+1>=n||nums[mid]>nums[mid+1])&&(mid-1<0||nums[mid]>nums[mid-1]))
            {
                return mid;
            }
            if(mid+1<=high) st.push(make_pair(mid+1,high));
            if(low<=mid-1) st.push(make_pair(low,mid-1));
        }
    }
};
