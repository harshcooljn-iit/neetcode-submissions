class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        for (int i=0;i<s.size();i++){
            // odd length
            int l = i, r = i;
            while (l>=0 && r<n && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
            // even length
            l = i, r = i+1;
            while (l>=0 && r<n && s[l]==s[r]){
                cnt++;
                l--;
                r++;
            }
        }
        return cnt;
    }
};
