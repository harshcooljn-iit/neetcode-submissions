class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1){
            return nums[0];
        }
        vector<int> dp(n+3,0);
        int ans = 0;
        for (int i=n-2;i>=0;i--){
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
        }
        ans = max(dp[0],ans);
        dp = vector<int>(n+3,0);
        for (int i=n-1;i>=1;i--){
            dp[i] = max(nums[i]+dp[i+2],dp[i+1]);
        }
        ans = max(ans, dp[1]);
        return ans;
    }
};
