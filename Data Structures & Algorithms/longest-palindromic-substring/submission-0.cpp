class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int> > ispal(n+1,vector<int>(n+1,0));
        int ans = 1;
        int x = 0, y=0;
        for (int i=0;i<n;i++){
            ispal[i][i] = 1;
            if (i+1<n){
                if (s[i]==s[i+1]){
                    ispal[i][i+1] = 1;
                    ans = 2;
                    x = i;
                    y = i+1;
                }
            }
        }

        for (int len = 3; len<=n;len++){
            for (int i=0;i+len-1<n;i++){
                int j = i + len - 1;
                ispal[i][j] = ((s[i]==s[j]) & (ispal[i+1][j-1]));
                if (ispal[i][j]){
                    if (len > ans){
                        ans = len;
                        x = i;
                        y = j;
                    }
                }
            }
        }
        cout << x << ' ' << y << endl;
        cout << ispal[x][y] << endl;
        return s.substr(x,ans);
    }
};
