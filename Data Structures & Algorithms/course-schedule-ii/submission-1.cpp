class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        // We need to find the topological ordering
        vector<vector<int> > g(n);
        vector<int> indeg(n);
        vector<int> order;
        vector<int> vis(n);
        for (auto& v: p){
            g[v[1]].push_back(v[0]);
            indeg[v[0]]++;
        }

        queue<int> q;
        for (int i=0;i<n;i++){
            if (indeg[i]==0){
                q.push(i);
            }
        }

        while (!q.empty()){
            int node = q.front();
            q.pop();
            order.push_back(node);
            if (vis[node]) continue;
            vis[node] = 1;
            for (auto& child: g[node]){
                indeg[child]--;
                if (indeg[child]==0){
                    q.push(child);
                }
            }
        }

        if (order.size()<n){
            order.clear();
        }
        return order;
    }
};
