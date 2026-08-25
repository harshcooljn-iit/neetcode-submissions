class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> f;
        int l = 0, r = -1;
        int ans = 1;
        int mxf = 0;
        while (l<s.size()){
            while (r+1<s.size()){
                r++;
                f[s[r]]++;
                int prev = mxf;
                mxf = max(mxf, f[s[r]]);
                if ((r-l+1 - mxf)>k){
                    f[s[r]]--;
                    r--;
                    mxf = prev;
                    break;
                }
            }
            cout << l << ' ' << r << endl;
            cout << "f\n";
            for (auto& c: f){
                cout << c.first << ' ' << c.second << endl;
            }
            ans = max(ans, r-l+1);
            if (l>r){
                l++;
                r=l-1;
            }
            else{
                f[s[l]]--;
                l++;
            }
        }
        
        return ans;
    }
};
