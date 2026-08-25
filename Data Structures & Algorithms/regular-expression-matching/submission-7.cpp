class Solution {
public:
    string s,t;
    int n,m;
    vector<vector<int> > dp;
    int f(int i, int j){
        if (i==n){
            if (j>=m){
                return 1;
            }
            else{
                if (j==m-1 && t[j]=='*'){
                    return 1;
                }
                else if (t[j+1]=='*'){
                    return f(i,j+2);
                }
                else{
                    return 0;
                }
            }
        }
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans = 0;
        if (t[j]!='.' && t[j]!='*'){
            if (s[i]!=t[j]){
                if (j+1<m && t[j+1]=='*'){
                    ans += f(i,j+1);
                }
            }
            else{
                ans += f(i+1,j+1);
                if (j+1<m && t[j+1]=='*'){
                    ans += f(i,j+1);
                }
            }
        }
        else if (t[j]=='.'){
            ans += f(i+1,j+1); // because . can be any char
            if (j+1<m && t[j+1]=='*'){
                ans += f(i,j+1);
            }
        }
        else{
            if (t[j-1]=='.' || t[j-1]==s[i]){
                ans += f(i+1,j+1) + f(i+1,j);
            }
            ans += f(i,j+1);
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string a, string b) {
        s = a;
        t = b;
        n = s.size();
        m = t.size();
        dp = vector<vector<int> >(n+1,vector<int>(m+1,-1));
        return f(0,0);
    }
};
