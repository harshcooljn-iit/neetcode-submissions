using ll = int;
class Solution {
public:
    int maxArea(vector<int>& h) {
        ll n = h.size();
        ll l=0,r=n-1;
        ll ans = 0;
        while (l<r){
            ans = max(ans,(r-l)*min(h[l],h[r]));
            if (h[l]<h[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};
