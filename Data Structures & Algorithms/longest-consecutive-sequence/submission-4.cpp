using ll = long long;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll n = nums.size();
        if (n==0){
            return 0;
        }
        ll prev = nums[0];
        ll i=1;
        ll cur=1;
        ll ans=1;
        while (i<n){
            if (nums[i]==prev+1){
                cur++;
            }
            else if (nums[i]!=prev){
                ans = max(ans,cur);
                cur=1;
            }
            prev=nums[i];
            i++;
        }
        ans = max(ans,cur);
        return ans;
    }
};
