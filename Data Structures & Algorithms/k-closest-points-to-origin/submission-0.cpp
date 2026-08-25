class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<double,int,int> > pq;
        for (auto& e: points){
            double d = sqrt(e[0]*e[0] + e[1]*e[1]);
            pq.push({-d,e[0],e[1]});
        }
        vector<vector<int> > ans;
        for (int i=0;i<k;i++){
            auto [d,x,y] = pq.top();
            ans.push_back({x,y});
            pq.pop();
        }
        return ans;
    }
};
