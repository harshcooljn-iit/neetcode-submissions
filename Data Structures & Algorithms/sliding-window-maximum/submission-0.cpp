class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        map<int,int> f;
        multiset<int> st;
        int l = 0;
        int r = 0;
        int mx = a[0];
        while (r<k){
            st.insert(a[r]);
            mx = max(mx, a[r]);
            f[a[r]]++;
            r++;
        }
        vector<int> ans;
        ans.push_back(mx);
        while (r<a.size()){
            // removing a[l]
            st.erase(st.find(a[l]));
            st.insert(a[r]);
            l++;
            mx = *st.rbegin();
            ans.push_back(mx);
            r++;
        }
        return ans;
    }
};
