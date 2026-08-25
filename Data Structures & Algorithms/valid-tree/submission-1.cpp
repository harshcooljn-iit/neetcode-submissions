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


    bool validTree(int n, vector<vector<int>>& edges) {
        // A valid tree has no cycles
        UnionFind uf(n);
        bool valid = true;
        for (auto& edge: edges){
            int x = edge[0], y = edge[1];
            if (uf.find(x)!=uf.find(y)){
                uf.merge(x,y);
            }
            else{
                valid = false;
                break;
            }
        }
        if (uf.size()>1) valid = false;
        return valid;
    }
};
