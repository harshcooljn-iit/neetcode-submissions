using ll = int;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ll n = nums.size();
        vector<ll>& a = nums;
        set<vector<ll> > ans;
        for (ll i=0;i<n;i++){
            ll l=0,r=n-1;
            while (l<i && r>i){
                if (a[l]+a[i]+a[r]<0){
                    l++;
                }
                else if (a[l]+a[i]+a[r]>0){
                    r--;
                }
                else{
                    vector<ll> an = {a[l],a[i],a[r]};
                    ans.insert(an);
                    l++;
                    r--;
                }
            }
        }
        vector<vector<ll> > v;
        for(auto& vec: ans){
            v.push_back(vec);
        }
        return v;
    }

};
