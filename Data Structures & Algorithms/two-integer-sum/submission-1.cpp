using ll = long long;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<pair<ll,ll> > st;
        ll n = nums.size();
        for (ll i=0;i<n;i++){
            st.insert({nums[i],i});
        }
        ll p = -1, q=-1;
        for (ll i=0;i<n;i++){
            ll rem = target - nums[i];
            auto it = st.lower_bound({rem,-1});
            if (it->second == i) it++;
            ll x = it->first;
            if (x==rem){
                p = i; q= it->second;
                break;
            }
        }
        return {p,q};
    }
};
