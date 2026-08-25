using ll = int;
using pll = pair<int,int>;
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // multisource bfs
        queue<pll > q;
        ll n = grid.size();
        ll m = grid[0].size();
        for (ll i=0;i<n;i++){
            for (ll j=0;j<m;j++){
                if (grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        vector<pll > movements = {
            {1,0},{0,1},{0,-1},{-1,0}
        };
        vector<vector<ll> > vis(n+1,vector<ll>(m+1,0));
        while (!q.empty()){
            pll p = q.front();
            ll i = p.first, j = p.second;
            q.pop();
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            for (auto& movement: movements){
                ll x = i + movement.first;
                ll y = j + movement.second;
                if ((x>=0&&y>=0&&x<n&&y<m&&grid[x][y]!=-1) && grid[x][y] > grid[i][j] + 1){
                    grid[x][y] = grid[i][j] + 1;
                    q.push({x,y});
                }
            }
        }

        return;
    }
};
