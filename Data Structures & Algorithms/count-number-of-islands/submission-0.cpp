using ll = int;
struct UnionFind{
    ll set_size,n,m;
    vector<vector<pair<ll,ll> > > par;
    vector<vector<ll> > rank;
    UnionFind(){}
    UnionFind(ll x, ll y, ll ones){
        n = x;
        m = y;
        set_size = ones;
        par.assign(n,vector<pair<ll,ll> >(m,{0,0}));
        rank.assign(n,vector<ll>(m,1));
        for (ll i=0;i<n;i++){
            for (ll j=0;j<m;j++){
                par[i][j] = {i,j};
            }
        }
    }

    pair<ll,ll> find(pair<ll,ll> node){
        if (node!=par[node.first][node.second]) return par[node.first][node.second] = find(par[node.first][node.second]);
        return node;
    }

    void merge(pair<ll,ll> x, pair<ll,ll> y){
        pair<ll,ll> px = find(x), py = find(y);
        if (px!=py){
            if (rank[px.first][px.second]<rank[py.first][py.second]){
                par[px.first][px.second] = py;
                rank[py.first][py.second] += rank[px.first][px.second];
            }
            else{
                par[py.first][py.second] = px;
                rank[px.first][px.second] += rank[py.first][py.second];
            }
            set_size--;
        }
    }

    ll size(){
        return set_size;
    }
};

class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
        ll n = grid.size(),m = grid[0].size();
        ll ones = 0;
        for (ll i=0;i<n;i++){
            for (ll j=0;j<m;j++){
                if (grid[i][j]=='1') ones++;
            }
        }
        UnionFind uf(n,m,ones);
        vector<pair<ll,ll> > movements = {
            {1,0},{0,1},{-1,0},{0,-1}
        };
        for (ll i=0;i<n;i++){
            for (ll j=0;j<m;j++){
                if (grid[i][j]=='0') continue;
                for (auto& movement: movements){
                    ll x = movement.first + i;
                    ll y = movement.second + j;
                    if (x>=0&&y>=0&&x<n&&y<m&&grid[x][y]=='1'){
                        uf.merge({i,j},{x,y});
                    }
                }
            }
        }

        return uf.size();
    }
};
