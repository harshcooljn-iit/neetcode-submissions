class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // for all 'O's find if they are connected to any edge 'O's 
        // for all those 'O's that are not connected to any edge 'O's 
        // change them to 'X'
        // So we can run a multisource bfs from all edge 'O's
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int> > dis(n,vector<int>(m,1e9)),vis(n,vector<int>(m));
        queue<pair<int,int> > q;
        for (int i=0;i<n;i++){
            if (i==0 || i==n-1){
                for (int j=0;j<m;j++){
                    if (board[i][j]=='O'){
                        q.push({i,j});
                        dis[i][j] = 0;
                    }
                }
                continue;
            }
            if (board[i][0]=='O'){
                q.push({i,0});
                dis[i][0] = 0;
            }
            if (board[i][m-1]=='O'){
                q.push({i,m-1});
                dis[i][m-1] = 0;
            }
        }
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        while (!q.empty()){
            auto node = q.front();
            q.pop();
            int i = node.first, j = node.second;
            if (vis[i][j]) continue;
            vis[i][j] = 1;
            for (int k=0;k<dx.size();k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if (x>=0 && y>=0 && x<n && y<m && board[x][y]=='O'){
                    if (dis[x][y] > dis[i][j] + 1){
                        dis[x][y] = dis[i][j] + 1;
                        q.push({x,y});
                    }
                }
            }
        }

        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (board[i][j]=='O'){
                    if (dis[i][j]==1e9) {
                        // not reachable
                        board[i][j] = 'X';
                    }
                }
            }
        }

        return;
    }
};
