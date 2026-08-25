using ll = int;
class Solution {
public:
    vector<string> v;
    void gen(int l, int r, string& s){
        if (l==0 && r==0){
            v.push_back(s);
            return;
        }
        if (l){
            s.push_back('(');
            gen(l-1,r,s);
            s.pop_back();
        }
        if (l < r){
            s.push_back(')');
            gen(l,r-1,s);
            s.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        string s = "";
        gen(n,n,s);
        return v;
    }
};
