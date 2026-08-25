class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto& e: nums){
            sum += e;
        }
        if (sum&1){
            return 0;
        }
        else{
            vector<vector<int> > dp(n+1,vector<int>(sum/2+1,0));
            for (int s = sum/2;s>=0;s--){
                if (s + nums[n-1] > sum/2) continue;
                else if (s + nums[n-1] == sum/2)
                dp[n-1][s] = 1;
            }

            for (int i = n-2;i>=0;i--){
                for (int s = sum/2;s>=0;s--){
                    dp[i][s] += dp[i+1][s];
                    if (s + nums[i]<=sum/2){
                        dp[i][s] += dp[i+1][s+nums[i]];
                    }
                }
            }
            return dp[0][0];
        }
    }
};
