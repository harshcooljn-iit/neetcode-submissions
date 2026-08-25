class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=-1;
        int cnt = 0;
        map<char,int> v;
        while (l<s.size()){
            while (r+1<s.size() && v[s[r+1]]==0){
                r++;
                v[s[r]]++;
            }
            cnt = max(cnt, r-l+1);
            if (l>r){
                l++;
                r=l-1;
            }
            else{
                v[s[l]]--;
                l++;
            }
        }
        return cnt;
    }
};
