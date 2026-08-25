class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,1e9));
        for (int i=n;i>=0;i--){
            for (int j=m;j>=0;j--){
                if (i==n && j==m){
                    dp[i][j]=0;
                }
                else if (i==n){
                    // then we can only insert
                    dp[i][j] = min(dp[i][j],1 + dp[i][j+1]);
                }
                else if (j==m){
                    // then we can only delete
                    dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]);
                }
                else{
                    if (s[i]==t[j]){
                        dp[i][j] = min(dp[i][j],dp[i+1][j+1]);
                    }
                    dp[i][j] = min(dp[i][j],1 + dp[i][j+1]); // insert
                    dp[i][j] = min(dp[i][j], 1 + dp[i+1][j]); // delete
                    dp[i][j] = min(dp[i][j], 1 + dp[i+1][j+1]); // replace
                }
            }
        }
        return dp[0][0];
    }
};
