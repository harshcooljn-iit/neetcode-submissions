class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if (s3.size()!=n+m){
            return false;
        }
        vector<vector<bool> > dp(n+1,vector<bool>(m+1,false));
        // dp[i][j] = can we form s3[i+j:] using s1[i:] and s2[j:]
        dp[n][m] = true;
        for (int i=n;i>=0;i--){
            for (int j=m;j>=0;j--){
                if (i<n && s1[i]==s3[i+j]){
                    dp[i][j] = dp[i][j] || dp[i+1][j];
                }
                if (j<m && s2[j]==s3[i+j]){
                    dp[i][j] = dp[i][j] || dp[i][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
