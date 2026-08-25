using ll = int;
class Solution {
public:
    bool isPalindrome(string s) {
        ll n = s.size();
        ll l = 0,r=n-1;
        while (l<=r){
            while (!isalnum(s[l]) && l<n){
                l++;
            }
            while (!isalnum(s[r]) && r>0){
                r--;
            }
            if (l>=n || r<0) break;
            if (tolower(s[l])!=tolower(s[r])){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
