class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,vector<string> > mp;
        for (auto& s: strs){
            vector<int> v(26);
            for (auto& e: s){
                v[e-'a']++;
            }
            mp[v].push_back(s);
        }
        for (auto& e: mp){
            ans.push_back(e.second);
        }
        return ans;
    }
};
