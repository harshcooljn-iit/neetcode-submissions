class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0
        mp = {}
        l = 0
        r = -1
        ans = 0
        while l < n:
            while r + 1 < n and s[r+1] not in mp:
                r += 1
                mp[s[r]] = r
            ans = max(ans, r-l+1)
            if l > r:
                l += 1
                r = l - 1
            else:
                mp.pop(s[l])
                l += 1
        return ans