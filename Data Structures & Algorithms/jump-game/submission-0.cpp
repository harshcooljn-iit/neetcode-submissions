class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> canReach(n);
        canReach[n-1] = 1;
        int idx = n-1;
        for (int i=n-2;i>=0;i--){
            if (nums[i]+i >= idx){
                idx = i;
                canReach[i] = 1;
            }
        }
        return canReach[0];
    }
};
