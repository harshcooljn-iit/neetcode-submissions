class Solution {
public:
    int longestCommonSubsequence(string t, string s) {
        int n = s.size();
        int m = t.size();
        vector<vector<int> > dp(n+1,vector<int>(m+1,0));
        // dp[i][j] = LCS in s[i:], t[j:]
        for (int i = n-1;i>=0;i--){
            for (int j=m-1;j>=0;j--){
                if (s[i]==t[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }
        return dp[0][0];
    }
};
