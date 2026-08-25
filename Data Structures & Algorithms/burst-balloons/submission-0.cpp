class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> a;
        a.push_back(1);
        for (auto& e: nums){
            a.push_back(e);
        }
        a.push_back(1);
        int n = nums.size();
        vector<vector<int> > dp(n+2, vector<int>(n+2,0));
        for (int len=1;len<=n;len++){
            for (int l=1;l+len-1<=n;l++){
                int r = l+len-1;
                for (int i=l;i<=r;i++){
                    // i is the last element to be popped in the current range
                    // so all elements in l,r except i will be popped and therefore 
                    // element i will have neighbours l-1 and r+1 at the end
                    dp[l][r] = max(dp[l][r], a[l-1]*a[i]*a[r+1] + dp[l][i-1] + dp[i+1][r]);
                }
            }
        }
        return dp[1][n];
    }
};
