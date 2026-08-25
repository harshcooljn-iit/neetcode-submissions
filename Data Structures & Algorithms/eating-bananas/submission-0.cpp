class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int n = p.size();
        sort(p.begin(),p.end());
        int lo = 1, hi = p[n-1];
        int ans = hi;
        while (lo<=hi){
            int k = (lo+hi)>>1;
            int time = 0;
            for (int i=0;i<n;i++){
                time += (p[i]+k-1)/k;
            }
            if (time<=h){
                ans = k;
                hi=k-1;
            }
            else{
                lo=k+1;
            }
        }
        return ans;
    }
    
};
