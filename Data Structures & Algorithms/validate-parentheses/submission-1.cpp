class Solution {
public:
    bool isValid(string s) {
       stack<char> stk;
       map<char,char> mp;
       mp[')']='(';
       mp['}']='{';
       mp[']']='[';
       for (auto c: s){
            // if (!stk.empty())
            // cout << c << ' ' << mp[stk.top()] << endl;
            if (c=='(' || c=='{' || c=='['){
                stk.push(c);
            }
            else{
                if (!stk.empty() && mp[c]==stk.top()){
                    stk.pop();
                }
                else{
                    return false;
                }
            }
       } 
       if (stk.empty()){
            return true;
       }
       else{
            return false;
       }
    }
};
