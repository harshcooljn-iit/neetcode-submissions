class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxlen = 1;
        for (int i=0;i<26;i++){
            char cur = 'A' + i;
            int l = 0, r = -1;
            int ans = 1;
            int rep = 0;
            while (l<s.size()){
                while (r+1<s.size() && (rep < k || s[r+1]==cur)){
                    r++;
                    if (s[r]!=cur){
                        rep++;
                    }
                }
                ans = max(ans, r-l+1);
                if (l>r){
                    l++;
                    r=l-1;
                }
                else{
                    if (s[l]!=cur){
                        rep--;
                    }
                    l++;
                }
            }
            maxlen = max(maxlen, ans);
        }
        return maxlen;
    }
};
