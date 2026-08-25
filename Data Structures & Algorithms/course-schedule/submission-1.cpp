class Solution {
public:
    vector<vector<int > > g; // adjacency list
    vector<int> vis;
    vector<int> instk;
    bool cycle = false;
    void dfs(int node){
        if (cycle) return;
        vis[node] = 1;
        instk[node] = 1;
        for (auto& child: g[node]){
            if (instk[child]){
                cycle = true;
                return;
            }
            else{
                dfs(child);
            }
        }
        instk[node] = 0;
    }

    bool canFinish(int n, vector<vector<int>>& p) {
        // we just need to detect a deadlock , or a cycle in a directed graph
        // Let us first construct the graph
        g.assign(n, vector<int>());
        vis.assign(n,0);
        instk.assign(n,0);
        for (auto& v: p){
            g[v[1]].push_back(v[0]); // dirceted since dependencies
        }
        
        for (int i=0;i<n;i++){
            if (!vis[i]){
                cycle = false;
                dfs(i);
            }
            if (cycle) break;
        }

        if (cycle){
            return false;
        }
        else{
            return true;
        }

    }
};
