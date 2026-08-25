class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int> > ans;
        int l = newInterval[0], r = newInterval[1];
        for (int i=0;i<n;i++){
            if (intervals[i][1] < l || intervals[i][0] > r){
                ans.push_back(intervals[i]);
            }
            // else if (l <= intervals[i][0] && intervals[i][1] <= r){
            //     continue;
            // }
            else{
                l = min(l, intervals[i][0]);
                r = max(r, intervals[i][1]);
            }
        }
        if (ans.empty()) {
            ans.push_back({l,r});
            return ans;
        }
        bool inserted = false;
        for (int i=0;i<ans.size();i++){
            if (ans[i][0] > r){
                ans.insert(ans.begin()+i, {l,r});
                inserted = true;
                break;
            }
        }
        if (!inserted){
            ans.push_back({l,r});
        }
        return ans;
    }
};
