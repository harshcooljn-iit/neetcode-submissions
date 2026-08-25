class Solution {
public:

    int f(int i, int rem, int n, vector<int>& a, vector<unordered_map<int,int> >& dp){
        if (i==n){
            if (rem!=0){
                return 0;
            }
            else{
                return 1;
            }
        }

        if (dp[i].find(rem)!=dp[i].end()){
            return dp[i][rem];
        }

        return dp[i][rem] = f(i+1,rem-a[i],n,a,dp) + f(i+1,rem+a[i],n,a,dp);
    }

    int findTargetSumWays(vector<int>& a, int t) {
        int n = a.size();
        vector<unordered_map<int,int> > dp(n+1);
        dp[n][t] = 1;
        for (int i=n-1;i>=0;i--){
            for (auto& e: dp[i+1]){
                dp[i][e.first-a[i]] += e.second;
                dp[i][e.first+a[i]] += e.second;
            }
        }
        return dp[0][0];
    }
};
