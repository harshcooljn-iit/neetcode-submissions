class Solution:
    def isPalindrome(self, s: str) -> bool:
        s1 = ""
        for i in range(len(s)):
            if s[i].isalnum():
                s1 += s[i]
        s = s1
        n = len(s)
        revs = s[-1:(n-1)//2:-1].lower()
        front = s[:n//2].lower()
        print(front, revs)
        return front == revs