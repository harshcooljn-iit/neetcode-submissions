class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(),m = matrix[0].size();
        int lo = 0, hi = n*m-1;
        int x = 0, y=0;
        while (lo<=hi){
            int mid = (lo+hi)>>1;
            int i = mid/m;
            int j = mid%m;
            if (matrix[i][j]<=target){
                x = i;
                y = j;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        if (matrix[x][y]==target) return true;
        return false;
    }
};
