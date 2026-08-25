class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int> > dis1(n,vector<int>(m,1e9));
        vector<vector<int> > dis2(n,vector<int>(m,1e9));
        vector<vector<int> > vis1(n,vector<int>(m,0));
        vector<vector<int> > vis2(n,vector<int>(m,0));

        queue<pair<int,int> > q1,q2;
        for (int i=0;i<n;i++){
            q1.push({i,0});
            dis1[i][0] = 0;
            q2.push({i,m-1});
            dis2[i][m-1] = 0;
        }
        for (int j=0;j<m;j++){
            q1.push({0,j});
            dis1[0][j] = 0;
            q2.push({n-1,j});
            dis2[n-1][j] = 0;
        }

        vector<pair<int,int> > movements = {
            {1,0},{0,1},{-1,0},{0,-1}
        };
        while (!q1.empty()){
            int i = q1.front().first;
            int j = q1.front().second;
            q1.pop();
            if (vis1[i][j]) continue;
            vis1[i][j] = 1;
            for (auto& movement: movements){
                int x = i + movement.first;
                int y = j + movement.second;
                if ((x>=0&&y>=0&&x<n&&y<m&&heights[x][y]>=heights[i][j]) && dis1[x][y] > dis1[i][j]+1){
                    dis1[x][y] = dis1[i][j]+1;
                    q1.push({x,y});
                }
            }
        }
        while (!q2.empty()){
            int i = q2.front().first;
            int j = q2.front().second;
            q2.pop();
            if (vis2[i][j]) continue;
            vis2[i][j] = 1;
            for (auto& movement: movements){
                int x = i + movement.first;
                int y = j + movement.second;
                if ((x>=0&&y>=0&&x<n&&y<m&&heights[x][y]>=heights[i][j]) && dis2[x][y] > dis2[i][j]+1){
                    dis2[x][y] = dis2[i][j]+1;
                    q2.push({x,y});
                }
            }
        }

        vector<vector<int> > cells;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (dis1[i][j]<1e9 && dis2[i][j]<1e9){
                    cells.push_back({i,j});
                }
            }
        }

        return cells;

    }
};
