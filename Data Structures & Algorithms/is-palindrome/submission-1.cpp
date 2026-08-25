class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (auto& e: s){
            if (isalnum(e)){
                t.push_back(tolower(e));
            }
        }
        s = t;
        reverse(t.begin(),t.end());
        return t==s;
    }
};
