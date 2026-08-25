class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int dp1 = 1, dp2 = 1;
        int ans = -1e9;
        for (int i=0;i<n;i++){
            if (nums[i]>0){
                dp1 *= nums[i];
                ans = max(ans, dp1);
                if (dp2<0){
                    dp2 *= nums[i];
                }
                else{
                    dp2 = 1;
                }
            }
            else if (nums[i]<0){
                if (dp2<0){
                    int temp = dp1;
                    dp1 = dp2 * nums[i];
                    dp2 = temp * nums[i];
                    ans = max(ans, dp1);
                }
                else{
                    dp2 = dp1 * nums[i];
                    dp1 = 1;
                }
            }
            else{
                dp1 = 1;
                dp2 = 1;
            }
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
