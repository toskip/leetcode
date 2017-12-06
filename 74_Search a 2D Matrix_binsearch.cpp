//记住这个写法吧 我觉得这是二分查找最好的写法
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n  = matrix[0].size();
        int  num = m*n;
        int low = 0;
        int high = num-1;
        int mid,i,j;
        while(low<=high)
        {
            mid= (low+high)/2;
            i = mid/n;
            j = mid%n;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target)
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
