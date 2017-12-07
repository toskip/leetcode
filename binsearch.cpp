//记住这个写法吧 我觉得这是二分查找最好的写法
class Solution {
public:
    bool binSearch(vector<int>& a, int target) {
        int low = 0;
        int high = a.size()-1;
        int mid;
        while(low<=high)
        {
            mid= (low+high)/2;
            if(a[mid]==target) return true;
            else if(a[mid]>target)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return false;
    }
};
