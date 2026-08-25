class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        sort(a.begin(),a.end());
        a.push_back({1000000000,1000000000});
        int n = a.size();
        int l = a[0][0], r = a[0][1];
        vector<vector<int> > b;
        for (int i=0;i<n-1;i++){
            if (a[i+1][0] <= r){
                r = max(r,a[i+1][1]);
            }
            else{
                b.push_back({l,r});
                l = a[i+1][0];
                r = a[i+1][1];
            }
        }
        return b;
    }
};
