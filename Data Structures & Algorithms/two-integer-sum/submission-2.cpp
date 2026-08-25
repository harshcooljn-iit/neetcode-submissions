class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        int n = nums.size();
        for (int i=0;i<n;i++){
            if (mp.find(target-nums[i]) != mp.end()){
                int j = mp[target-nums[i]];
                return {j,i};
            }
            mp[nums[i]] = i;
        }
    }
};
