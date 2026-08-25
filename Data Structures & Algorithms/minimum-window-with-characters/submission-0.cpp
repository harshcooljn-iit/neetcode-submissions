class Solution {
public:
    string minWindow(string s, string t) {
       // as soon as a valid substring is found from l to r
       // we can shift l
        map<char,int> f1,f2;
        int dist = 0;
        for (auto c: t){
            if (f1[c]==0) dist++;
            f1[c]++;
        }
        cout << dist << endl;
        int l = 0, r = -1;
        int cnt = 0;
        int lo=l,hi=r,len=0;
        while (l<s.size()){
            while (r+1<s.size() && (cnt<dist)){
                r++;
                f2[s[r]]++;
                if (f1[s[r]]>0 && (f2[s[r]]==f1[s[r]])){
                    cnt++;
                }
            }
            cout << l << ' ' << r << endl;
            if (cnt==dist && (len==0 || (r-l+1)<len)){
                len = r-l+1;
                lo=l;
                hi=r;
            }
            if (l>r){
                l++;
                r=l-1;
            }
            else{
                if (f1[s[l]]>0 && f2[s[l]]==f1[s[l]]){
                    cnt--;
                }
                f2[s[l]]--;
                l++;
            }
        }
        if (lo>hi){
            return "";
        }
        cout << lo << ' ' << hi << endl;
        return s.substr(lo,hi-lo+1);
    }
};
