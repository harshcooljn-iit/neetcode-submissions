using ll = long long;
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<ll,ll> mp;
        bool ans = false;
        for (auto& e: nums){
            mp[e]++;
            ans = ans | (mp[e]>1);
        }
        return ans;
    }
};
