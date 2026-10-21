class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n = len(s2)
        m = len(s1)
        f = [0]*26
        for c in s1:
            f[ord(c)-ord('a')] += 1
        l, r = 0, -1
        cur = [0]*26
        exists = False
        while l < n:
            while r+1<n and cur[ord(s2[r+1])-ord('a')] < f[ord(s2[r+1])-ord('a')]:
                r += 1
                cur[ord(s2[r])-ord('a')] += 1
            check = True
            for i in range(26):
                if cur[i] != f[i]:
                    check = False
                    break
            if check:
                return True
            if l > r:
                l += 1
                r = l - 1
            else:
                cur[ord(s2[l])-ord('a')] -= 1
                l += 1
        return False
