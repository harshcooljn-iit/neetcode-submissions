class Solution {
public:

    int f(int i, int n, string& s, vector<int>& dp){
        if (i>=n) return 1;
        if (s[i]=='0') return 0;
        if (dp[i]!=-1){
            return dp[i];
        }
        int ans = f(i+1,n,s,dp);
        int num = stoi(s.substr(i,2));
        if (num >= 10 && num <= 26){
            ans += f(i+2,n,s,dp);
        }
        return dp[i] = ans;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+3,-1);
        return (f(0,n,s,dp));
    }
};
