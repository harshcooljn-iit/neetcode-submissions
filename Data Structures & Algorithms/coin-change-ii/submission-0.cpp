class Solution {
public:
    int change(int n, vector<int>& coins) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for (auto& e: coins){
            for (int i=0;i<=n;i++){
                if (i+e <= n){
                    dp[i+e] += dp[i];
                }
            }
        }
        return dp[n];
    }
};
