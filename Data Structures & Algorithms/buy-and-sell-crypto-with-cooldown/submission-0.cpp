class Solution {
public:

    int f(int i, int prev, int n, vector<int>& prices, vector<vector<int>>& dp){
        if (i>n){
            return 0;
        }
        if (dp[i][prev]!=-1){
            return dp[i][prev];
        }
        int ans = 0;
        if (prev==0){
            // can buy here or in the future
            ans = max(f(i+1,i,n,prices,dp),f(i+1,prev,n,prices,dp));
        }
        else{
            // can sell here or not
            ans = max(prices[i-1] - prices[prev-1] + f(i+2,0,n,prices,dp), f(i+1,prev,n,prices,dp));
        }
        return dp[i][prev] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int> > dp(n+2,vector<int>(n+2,-1));
        return f(1,0,n,prices,dp);
    }
};
