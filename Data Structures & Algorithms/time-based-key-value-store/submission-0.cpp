class TimeMap {
public:
    map<string,vector<pair<int,string> > > mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        auto &st = mp[key];
        if (st.empty()) return "";
        int lo = 0, hi = st.size()-1;
        int ans = 0;
        while (lo<=hi){
            int mid = (lo+hi)>>1;
            if (st[mid].first <= timestamp){
                ans = mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        if (st[ans].first <= timestamp){
            return st[ans].second;
        }
        else{
            return "";
        }

    }
};
