class Solution:

    def encode(self, strs: List[str]) -> str:
        e = ""
        for s in strs:
            l = len(s)
            e += str(l) + "," + s
        print(e)
        return e


    def decode(self, s: str) -> List[str]:
        strs = []
        prev = 0
        i = 0
        while i < len(s):
            if s[i] == ',':
                print(prev, i, s[prev:i])
                if prev != i:
                    l = int(s[prev:i])
                else:
                    l = 0
                strs.append(s[i+1:i+1+l])
                i = i + 1 + l
                prev = i
            i += 1
        return strs
        