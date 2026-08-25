class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int> > dis(n,vector<int>(m,1e8));
        vector<vector<int> > vis(n,vector<int>(m,0));
        queue<pair<int,int> > q;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==2){
                    q.push({i,j});
                    dis[i][j] = 0;
                }
            }
        }
        vector<pair<int,int> > movements = {
            {1,0},{0,1},{-1,0},{0,-1}
        };
        while (!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            for (auto& movement: movements){
                int x = i + movement.first;
                int y = j + movement.second;
                if ((x>=0&&y>=0&&x<n&&y<m&&grid[x][y]==1) && dis[x][y] > dis[i][j] + 1){
                    dis[x][y] = dis[i][j] + 1;
                    q.push({x,y});
                }
            }
        }

        int ans = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==1){
                    ans = max(ans, dis[i][j]);
                }
            }
        }

        if (ans==1e8) ans = -1;
        return ans;
    }
};
