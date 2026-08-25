using ll = long long;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<ll,ll> mp;
        set<pair<ll,ll> > st;
        for (auto& e: nums){
            auto it = st.find({-mp[e],e});
            if (it!=st.end()){
                st.erase(it);
            }
            mp[e]++;
            st.insert({-mp[e],e});
        }
        ll cnt = 0;
        vector<int> topK;
        for (auto& e: st){
            topK.push_back(e.second);
            cnt++;
            if (cnt==k) break;
        }
        return topK;

    }
};
