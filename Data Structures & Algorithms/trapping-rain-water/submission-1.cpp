class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> p(n+2),s(n+2);
        for (int i=1;i<=n;i++){
            p[i] = max(p[i-1],h[i-1]);
        }
        for (int i=n;i>=1;i--){
            s[i] = max(s[i+1],h[i-1]);
        }
        int ans = 0;
        for (int i=0;i<n;i++){
            ans += max(0, min(p[i+1],s[i+1])-h[i]);
        }
        return ans;
    }
};
