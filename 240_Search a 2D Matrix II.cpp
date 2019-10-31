class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int n = matrix[0].size();
        if(!n) return false;
        int i = m-1;
        int j = 0;
        while(i>=0 && j<n){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) j++;
            else i--;
        }
        return false;
    }
};
