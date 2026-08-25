class Solution {
public:

    int f(int i, int n, vector<int>& cost){
        if (i>=n) return 0;
        int ans = cost[i] + min(f(i+1,n,cost),f(i+2,n,cost));
        return ans;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // return min(f(0,n,cost),f(1,n,cost));
        vector<int> dp(n+3,0);
        for (int i=n-1;i>=0;i--){
            dp[i] = cost[i] + min(dp[i+1],dp[i+2]);
            cout << dp[i] << ' ';
        }
        return min(dp[0],dp[1]);
    }
};
