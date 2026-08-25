class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        stack<pair<int,int> > stk;
        int n = a.size();
        vector<int> res(n);
        for (int i=n-1;i>=0;i--){
            while (!stk.empty() && stk.top().first <= a[i]){
                stk.pop();
            }
            if (stk.empty()) res[i]=0;
            else res[i] = stk.top().second - i;
            stk.push({a[i],i});

        }
        return res;
    }
};
