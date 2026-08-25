class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        s = "$" + s;
        unordered_map<string,int> mp;
        int m = 1;
        for (int i=0;i<wordDict.size();i++){
            mp[wordDict[i]] = i;
            m = max(m, int(wordDict[i].size()));
        }

        vector<int> dp(n+3,0);
        dp[0] = 1;
        // dp[i] = 1 if can break s[1:i] else 0
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                int l = i-j+1;
                if (l<=0) break;
                string word = s.substr(l, j);
                if (mp.find(word)!=mp.end()){
                    dp[i] |= dp[l-1];
                }
            }
        }

        return dp[n];

    }
};
