class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        map<int,int> mp,f;
        for (auto& e: a){
            if (mp.find(e[0]) == mp.end()){
                mp[e[0]] = e[1];
            }
            else{
                mp[e[0]] = min(mp[e[0]],e[1]);
            }
            f[e[0]]++;
        }
        int ans = 0;
        vector<vector<int> > b;
        for (auto& [l,r]: mp){
            ans += f[l]-1;
            if (b.empty() || b.back()[1] <= l){
                b.push_back({l,r});
            }
            else{
                b[b.size()-1][1] = min(b.back()[1], r);
                ans++;
            }
        }
        return ans;
    }
};
