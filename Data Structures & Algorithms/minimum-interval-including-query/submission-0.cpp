class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& a, vector<int>& q) {
        // sweepline is basically events strategy
        vector<tuple<int,int,int> > events;
        // l < q < r 
        // l should come before q and q should come before r
        // l -> -1 , q -> 0 , r -> 1
        for (int i=0;i<a.size();i++){
            events.push_back({a[i][0],-1,i});
            // events.push_back({a[i][1],1,i});
        }
        for (int i=0;i<q.size();i++){
            events.push_back({q[i],0,i});
        }
        sort(events.begin(),events.end());
        int n = events.size();
        priority_queue<pair<int,int> > pq;
        // pq will store active events
        vector<int> ans(q.size());
        for (int i=0;i<n;i++){
            auto [x,type,idx] = events[i];
            if (type == -1){
                // new interval starts here
                pq.push({-(a[idx][1]-a[idx][0]+1), -x});
            }
            else if (type == 0){
                // query
                // first remove all inactive intervals
                while (!pq.empty()){
                    auto [len, start] = pq.top();
                    len = -len;
                    start = -start;
                    if (len + start - 1 < x) pq.pop();
                    else break;
                }
                ans[idx] = -1;
                if (!pq.empty()) ans[idx] = -pq.top().first;
            }
            // else{

            // }
        }
        return ans;
    }
};
