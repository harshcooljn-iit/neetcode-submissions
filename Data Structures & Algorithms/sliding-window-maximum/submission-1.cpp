class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i=0;i<a.size();i++){
            while (!dq.empty() && a[dq.back()] < a[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if (i>=k-1){
                while (dq.front() <= i-k){
                    dq.pop_front();
                }
                ans.push_back(a[dq.front()]);
            }
        }
        cout << endl;
        return ans;
    }
};
