class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2));
        // dp[i][0] -> max profit from i to n , if no coin has been bought before
        // dp[i][1] -> max profit from i to n , if a coin has been brought before
        for (int i=n-1;i>=0;i--){
            // for 0        dont buy      buy
            dp[i][0] = max(dp[i+1][0], -prices[i] + dp[i+1][1]);
            // for 1        dont sell      
            dp[i][1] = max(dp[i+1][1], prices[i] + dp[i+2][0]);
        }
        return dp[0][0];
    }
};
