class Solution {
public:
    string s1,s2,s3;
    int n,m;
    vector<vector<vector<int> > > dp,done;
    int f(int i, int j, int k, int prev=-1){
        if (k == n+m){
            // we have reached the end of s3
            return 0;
        }

        if (done[i][j][k]){
            return dp[i][j][k];
        }
        // prev indicates that which string is it currently part of 
        int ans = -1e9; // this will indicate if s3 is an interleave
        if (prev==0){
            // can be a part of s1
            if (i<n && s1[i]==s3[k]){
                int o1 = 1 + f(i+1,j,k+1,1);
                ans = o1;
            }
            if (abs(ans)<=1){
                done[i][j][k] = 1;
                return dp[i][j][k] = ans;
            }
            // can be a part of s2
            if (j<m && s2[j]==s3[k]){
                int o2 = -1 + f(i,j+1,k+1,2);
                ans = o2;
            }
        }
        else if (prev==1){
            // can continue in s1
            if (i<n && s1[i]==s3[k]){
                int o1 = f(i+1,j,k+1,1);
                ans = o1;
            }
            if (abs(ans)<=1){
                done[i][j][k] = 1;
                return dp[i][j][k] = ans;
            }
            // can switch to s2
            if (j<m && s2[j]==s3[k]){
                int o2 = -1 + f(i,j+1,k+1,2);
                ans = o2;
            }
        }
        else{
            // can switch to s1
            if (i<n && s1[i]==s3[k]){
                int o1 = 1 + f(i+1,j,k+1,1);
                ans = o1;
            }
            if (abs(ans)<=1){
                done[i][j][k] = 1;
                return dp[i][j][k] = ans;
            }
            // can continue in s2
            if (j<m && s2[j]==s3[k]){
                int o2 = f(i,j+1,k+1,2);
                ans = o2;
            }
        }
        done[i][j][k] = 1;
        return dp[i][j][k] = ans;
    }

    bool isInterleave(string t1, string t2, string t3) {
        s1 = t1;
        s2 = t2;
        s3 = t3;
        n = s1.size();
        m = s2.size();
        if (s3.size()!=n+m){
            return 0;
        }
        dp = vector<vector<vector<int>>>(n+1,vector<vector<int>>(m+1,vector<int>(n+m+2,-1e9)));
        done = vector<vector<vector<int>>>(n+1,vector<vector<int>>(m+1,vector<int>(n+m+2,0)));
        int ans = f(0,0,0);
        if (abs(ans)<=1) ans = 1;
        else ans = 0;
        return ans;
    }
};
