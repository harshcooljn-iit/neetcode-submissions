class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> nxt_small(n),prev_small(n);
        stack<int> stk;
        for (int i=n-1;i>=0;i--){
            while (!stk.empty() && h[stk.top()]>=h[i]){
                stk.pop();
            }
            if (stk.empty()) nxt_small[i]=n;
            else nxt_small[i] = stk.top();
            stk.push(i);
        }  
        while (!stk.empty()) stk.pop();
        for (int i=0;i<n;i++){
            while (!stk.empty() && h[stk.top()]>=h[i]){
                stk.pop();
            }
            if (stk.empty()) prev_small[i]=-1;
            else prev_small[i] = stk.top();
            stk.push(i);
        } 
        for (int i = 0;i<n;i++){
            cout << nxt_small[i] << ' ';
        }
        cout << endl;
        int ans = 0;
        for (int i = 0;i<n;i++){
            ans = max(ans,h[i]*(nxt_small[i]-prev_small[i]-1));
        }
        return ans;
    }
};
