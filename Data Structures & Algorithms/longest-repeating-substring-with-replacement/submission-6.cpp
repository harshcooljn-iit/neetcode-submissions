class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = -1;
        int count[26] = {0};
        int max_freq = 0;
        int ans = 0;

        while (l < n) {
            while (r + 1 < n) {
                r++;
                count[s[r] - 'A']++;
                max_freq = max(max_freq, count[s[r] - 'A']);

                // If invalid, revert the expansion and break to shrink 'l'
                if ((r - l + 1) - max_freq > k) {
                    count[s[r] - 'A']--;
                    r--;
                    break;
                }
            }

            ans = max(ans, r - l + 1);

            if (l > r) {
                l++;
                r = l - 1;
            } else {
                count[s[l] - 'A']--;
                l++;
            }
        }

        return ans;
    }
};
