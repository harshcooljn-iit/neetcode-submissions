using tii = tuple<int,int,int>;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<int,int,int> > pq;
        for (auto& e: points){
            int d = e[0]*e[0] + e[1]*e[1];
            if (pq.size() < k)
            pq.push({d,e[0],e[1]});
            else{
                auto [d1,a,b] = pq.top();
                // cout << d1 << ' ' << d << endl;
                if (d < d1){
                    pq.pop();
                    pq.push({d,e[0],e[1]});
                }
            }
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
