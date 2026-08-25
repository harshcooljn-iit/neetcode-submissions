class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        int n = grid.size(), m = grid[0].size();
        priority_queue<tuple<int,int,int> > pq;
        vector<vector<int> > dis(n+1,vector<int>(m+1,1e9));
        pq.push({-grid[0][0], 0,0});
        dis[0][0] = grid[0][0];
        vector<vector<int> > vis(n+1,vector<int>(m+1,0));
        while (!pq.empty()){
            auto [dist, x, y] = pq.top();
            pq.pop();
            dist *= -1;
            cout << x << ' ' << y << endl;
            if (vis[x][y]) continue;
            vis[x][y] = 1;
            for (int k=0;k<dx.size();k++){
                int i = x + dx[k];
                int j = y + dy[k];
                if (i>=0 && j>=0 && i<n && j<m && (dis[i][j] > max(grid[i][j],dist))){
                    dis[i][j] = max(dist, grid[i][j]);
                    pq.push({-dis[i][j], i, j});
                }
            }
        }
        return dis[n-1][m-1];
    }
};
