using ll = int;
class Solution {
public:
    vector<vector<int> > twoSum(vector<int>& numbers, int target) {
        vector<vector<int> > vec;
        for (ll i=0;i<numbers.size();i++){
            ll b = lower_bound(numbers.begin(),numbers.end(),target-numbers[i]) - numbers.begin();
            if (b<numbers.size() && b>=0 && b!=i && numbers[i]+numbers[b]==target) vec.push_back({i,b});
        }
        return vec;
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll n = nums.size();
        set<multiset<int> > st;
        for (ll i=0;i<n;i++){
            vector<vector<int> > v = twoSum(nums,-nums[i]);
            if (!v.empty()){
                for (auto& vc: v){
                    ll a = vc[0], b = vc[1];
                    multiset<ll> s;
                    if (a!=i && b!=i){
                        s.insert(nums[i]);
                        s.insert(nums[a]);
                        s.insert(nums[b]);
                        st.insert(s);
                    }
                }
            }
        }
        vector<vector<int> > vec;
        for (auto& s: st){
            vector<int> v;
            for (auto& e: s){
                v.push_back(e);
            }
            vec.push_back(v);
        }
        return vec;
    }

};
