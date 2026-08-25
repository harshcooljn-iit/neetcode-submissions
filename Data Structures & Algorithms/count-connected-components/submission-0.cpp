class Solution {
public:

     struct UnionFind {
        int n, st_size;
        vector<int> par, rank;
        UnionFind(int x){
            n = x;
            st_size = x;
            par.assign(n,0);
            rank.assign(n,0);
            for (int i=0;i<n;i++){
                par[i] = i;
                rank[i] = 1;
            }
        }

        int find(int x){
            if (x == par[x]) return x;
            return par[x] = find(par[x]);
        }

        void merge(int x, int y){
            int parx = find(x), pary = find(y);
            if (parx!=pary){
                if (rank[parx] > rank[pary]){
                    rank[parx] += rank[pary];
                    par[pary] = parx;
                }
                else{
                    rank[pary] += rank[parx];
                    par[parx] = pary;
                }
                st_size--;
            }
        }

        int size(){
            return st_size;
        }
    };

    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto& edge: edges){
            uf.merge(edge[0], edge[1]);
        }
        return uf.size();
    }
};
