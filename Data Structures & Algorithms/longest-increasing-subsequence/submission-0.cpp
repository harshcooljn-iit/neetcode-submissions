class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;
        for (int i=0;i<n;i++){
            if (dp.empty() || dp.back() < nums[i]){
                dp.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
                dp[idx] = nums[i];
            }
        }
        return dp.size();
    }
};
