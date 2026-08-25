using ll = int;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<ll> > rowcnt,colcnt;
        rowcnt.assign(10,vector<ll>(10,0));
        colcnt.assign(10,vector<ll>(10,0));
        vector<vector<vector<ll> > > gridcnt(3,vector<vector<ll> >(3,vector<ll>(10,0)));
        for (ll i=0;i<9;i++){
            for (ll j=0;j<9;j++){
                if (board[i][j]<='0' || board[i][j]>'9') continue;
                ll num = board[i][j]-'0';
                rowcnt[i][num]++;
                colcnt[j][num]++;
                gridcnt[i/3][j/3][num]++;
                ll r,c,g;
                r = rowcnt[i][num];
                c = colcnt[j][num];
                g = gridcnt[i/3][j/3][num];
                if (r>1 || c>1 || g>1){
                    return false;
                }
            }
        }
        return true;
    }
};
