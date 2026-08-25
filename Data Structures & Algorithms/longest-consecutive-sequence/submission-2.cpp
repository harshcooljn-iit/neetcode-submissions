using ll = long long;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll n = nums.size();
        if (n==0){
            return 0;
        }
        vector<ll> cur(n,1);
        map<ll,set<ll> > mp;
        for (ll i=0;i<n;i++){
            mp[nums[i]].insert(i);
        }
        ll i=1;
        while (i<n){
            auto it = mp[nums[i]-1].lower_bound(i);
            if (it!=mp[nums[i]-1].begin()){
                it--;
                cur[i] = max(cur[i],1+cur[*it]);
            }
            i++;
        }
        ll ans = 1;
        for (ll i=0;i<n;i++){
            ans = max(ans,cur[i]);
        }
        return ans;
    }
};
