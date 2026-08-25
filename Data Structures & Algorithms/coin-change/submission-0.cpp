class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        vector<int> dp(n+3,1e9);
        dp[0] = 0;
        for (int i=1;i<=n;i++){
            for (auto& c: coins){
                if (c>i) continue;
                dp[i] = min(dp[i],1+dp[i-c]);
            }
        }
        if (dp[n]==1e9) dp[n] = -1;
        return dp[n];
    }
};
