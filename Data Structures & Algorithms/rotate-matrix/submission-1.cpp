class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // For each position there are 4 possible nodes based on the degree of rotation
        // for each call we are processing 4 nodes 
        // so in total we need (n*n)/4 calls
        int cnt = (n*n)/4;
        for (int i=0;i<n;i++){
            for (int j=i;j<n-i-1;j++){
                if (cnt==0) break;
                int x = j, y = n-i-1;
                int newn = matrix[i][j];
                int oldn = matrix[x][y];
                cout << "ij\n";
                cout << i << ' ' << j << endl;
                while (!(x==i && y==j)){
                    cout << x << ' ' << y << ' ' << newn << ' ' << oldn << endl;
                    matrix[x][y] = newn;
                    newn = oldn;
                    int newx = y, newy = n-x-1;
                    x = newx, y = newy;
                    oldn = matrix[x][y];
                }
                matrix[i][j] = newn;
                cnt--;
            }
            if (cnt==0) break;
        }
    }
};
