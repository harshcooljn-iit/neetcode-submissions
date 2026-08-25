class Solution {
public:
    int n,m;
    vector<int> dx = {1,0,0,-1};
    vector<int> dy = {0,1,-1,0};
    int f(int i, int j, vector<vector<int>>& matrix){
        if (i==n+1 || j==m+1 || i==0 || j==0){
            return 0;
        }
        // if (dp[i][j]!=-1){
        //     return dp[i][j];
        // }
        int mi = i-1, mj = j-1;
        int ans = 1;
        for (int k=0;k<dx.size();k++){
            int x = mi + dx[k];
            int y = mj + dy[k];
            if (x>=0&&y>=0&&x<n&&y<m){
                if (matrix[x][y]>matrix[mi][mj]){
                    ans = max(ans, 1 + f(x+1,y+1,matrix));
                }
            }
        }
        return ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int> > dp(n+2,vector<int>(m+2,-1));
        int ans = 1;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                ans = max(ans, f(i+1,j+1,matrix));
            }
        }
        return ans;
    }
};
