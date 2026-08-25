#define fr(i,a,n) for(int i=a;i<n;i++)
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> lm(n),rm(n);
        lm[0]=h[0];
        rm[n-1] = h[n-1];
        fr(i,1,n){
            lm[i]=max(lm[i-1],h[i]);
            rm[n-i-1]=max(rm[n-i],h[n-i-1]);
        }

        int ans = 0;
        fr(i,1,n-1){
            int water = min(lm[i-1],rm[i+1])-h[i];
            if (water>0) ans += water;
        }
        return ans;
    }
};
