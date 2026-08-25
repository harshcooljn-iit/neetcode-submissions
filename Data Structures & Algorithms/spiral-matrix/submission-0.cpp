class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> spiral;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};
        int i = 0, j = -1;
        // Only take a right turn if can't go ahead
        int k = 0;
        while (spiral.size() < n*m){
            int next_i = i + dx[k], next_j = j + dy[k];
            if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < m && matrix[next_i][next_j]!=1000){
                i = next_i;
                j = next_j;
                spiral.push_back(matrix[i][j]);
                matrix[i][j] = 1000; // to indicate that this has been visited since numbers are between [-100,100]
            }
            else{
                // take a right
                k = (k+1)%4;
            }
        }

        return spiral;
    }
};
