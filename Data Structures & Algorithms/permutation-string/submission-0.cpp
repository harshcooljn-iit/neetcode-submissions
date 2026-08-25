class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> f,f2;
        for (auto& c: s1){
            f[c]++;
        }
        int fsize = f.size();
        int l = 0, r = -1;
        int cnt = 0;
        while (l<s2.size()){
            while (r+1<s2.size() && (f2[s2[r+1]]+1<=f[s2[r+1]])){
                r++;
                f2[s2[r]]++;
                if (f2[s2[r]]==f[s2[r]]) cnt++;
            }
            cout << l << ' ' << r << ' ' << cnt << endl;
            if (cnt==fsize){
                return true;
            }
            if (l>r){
                l++;
                r=l-1;
            }
            else{
                if (f2[s2[l]]==f[s2[l]]) cnt--;
                f2[s2[l]]--;
                l++;
            }
        }
        return false;
    }
};
