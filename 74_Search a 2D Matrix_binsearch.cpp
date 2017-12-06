//想一想二分查找怎么写最简洁又不容易出错
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n  = matrix[0].size();
        if(n==0) return false;
        int  num = m*n;
        int low = 0;
        int high = num-1;
        int mid = (low+high)/2;
        int i = mid/n;
        int j = mid%n;
        while(low<high)
        {
            //cout<<low<<' '<<high<<' '<<mid<<' '<<i<<' '<<j<<endl;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target)
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
            mid= (low+high)/2;
            i = mid/n;
            j = mid%n;
            //cout<<low<<' '<<high<<' '<<mid<<' '<<i<<' '<<j<<endl;
        }
        if(matrix[i][j]==target) return true;
        return false;
    }
};
