class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int> > vec;
        for (int i=0;i<n;i++){
            vec.push_back({position[i],speed[i]});
        }
        sort(vec.begin(),vec.end());
        vector<double> time(n);
        for (int i=0;i<n;i++){
            time[i] = (target-vec[i].first)/(1.0*vec[i].second);
        }
        stack<double> stk;
        stk.push(time[n-1]);
        for (int i=n-2;i>=0;i--){
            if (time[i] <= stk.top()){
                continue;
            }
            else{
                stk.push(time[i]);
            }
        }
        return stk.size();

    }
};
