class Solution {
public:

    static bool cmp(vector<int>& a1, vector<int>& a2){
        if (a1[1] == a2[1]) return a1[0]<a2[0];
        return a1[1] < a2[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& a) {
        // dp[i] = # of intervals we can keep from [0:i] such that they are non-overlapping
        sort(a.begin(),a.end(),cmp);
        vector<int> dp(a.size());
        dp[0] = 1; // can always take the first interval by itself
        for (int i=1;i<a.size();i++){
            // option 1 is to skip interval i
            dp[i] = dp[i-1];
            // option 2 is to find a idx such that a[idx][1] <= a[i][0]
            // binary search
            int lo = 0, hi = a.size(), mid;
            int idx = -1;
            while (lo <= hi){
                mid = (lo + hi) >> 1;
                if (a[mid][1] <= a[i][0]){
                    idx = mid;
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }
            if (idx != -1)
            dp[i] = max(dp[i], 1 + dp[idx]);
        }
        return a.size() - dp.back();
    }
};
