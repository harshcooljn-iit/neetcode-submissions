class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int> > ans;
        int l = newInterval[0], r = newInterval[1];
        bool inserted = false;
        for (int i=0;i<n;i++){
            if (intervals[i][1] < l){
                ans.push_back(intervals[i]);
            }
            else if (intervals[i][0] > r){
                if (!inserted){
                    ans.push_back({l,r});
                    inserted=true;
                }
                if (inserted){
                    ans.push_back(intervals[i]);
                }
            }
            // else if (l <= intervals[i][0] && intervals[i][1] <= r){
            //     continue;
            // }
            else{
                l = min(l, intervals[i][0]);
                r = max(r, intervals[i][1]);
            }
        }
        if (!inserted){
            ans.push_back({l,r});
        }
        return ans;
    }
};
