using ll = int;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ll n = nums.size();
        vector<ll> pp(n),sp(n);
        pp[0] = nums[0];
        sp[n-1] = nums[n-1];
        for (ll i=1;i<n;i++){
            pp[i] = nums[i]*pp[i-1];
            sp[n-i-1] = nums[n-i-1]*sp[n-i];
        }
        vector<ll> output(n,1);
        for (ll i=0;i<n;i++){
            if (i>0){
                output[i] *= pp[i-1];
            }
            if (i<n-1){
                output[i] *= sp[i+1];
            }
        }
        return output;

    }
};
