class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = -1;
        map<char,int> mp;
        set<pair<int,char> > st;
        int change = 0;
        int ans = 1;
        while (l < n){
            while (r + 1 < n){
                r++;
                st.erase({mp[s[r]],s[r]});
                mp[s[r]]++;
                st.insert({mp[s[r]],s[r]});
                auto [fmax, cmax] = *st.rbegin();
                change = r-l+1 - fmax;
                if (change > k){
                    st.erase({mp[s[r]],s[r]});
                    mp[s[r]]--;
                    if (mp[s[r]]){
                        st.insert({mp[s[r]],s[r]});
                    }
                    r--;
                    break;
                }
            }
            // cout << l << ' ' << r << endl;
            ans = max(ans, r-l+1);
            if (l > r){
                l++;
                r = l-1;
            }
            else{
                st.erase({mp[s[l]],s[l]});
                mp[s[l]]--;
                if (mp[s[l]]){
                    st.insert({mp[s[l]],s[l]});
                }
                if (st.empty()){
                    change = 0;
                }
                else{
                    auto [fmax, cmax] = *st.rbegin();
                    change = (r-l) - fmax;
                }
                l++;
            }
        }
        return ans;
    }
};
