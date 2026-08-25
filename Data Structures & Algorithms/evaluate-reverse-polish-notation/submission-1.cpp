class Solution {
public:
    int evalRPN(vector<string>& token) {
        stack<int> stk;
        for (int i = 0;i<token.size();i++){
            if (token[i]!="+" && token[i]!="-" && token[i]!="*" && token[i]!="/"){
                int n = stoi(token[i]);
                stk.push(n);
            }
            else{
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int res;
                if (token[i]=="+"){
                    res = a + b;
                }
                else if (token[i]=="-"){
                    res = b - a;
                }
                else if (token[i]=="*"){
                    res = a * b;
                }
                else{
                    res = b / a;
                }
                stk.push(res);
            }
        }
        return stk.top();
    }
};
