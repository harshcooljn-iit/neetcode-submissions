class Solution {
public:
    set<vector<int> > subsets;
    vector<int> subset;
    void func(int i, vector<int>& a){
        if (i==a.size()){
            auto copysub = subset;
            sort(copysub.begin(), copysub.end());
            subsets.insert(copysub);
            return;
        }

        func(i+1,a);
        subset.push_back(a[i]);
        func(i+1,a);
        subset.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        func(0,nums);
        vector<vector<int> > vec;
        for (auto& v: subsets){
            vec.push_back(v);
        }
        return vec;
    }
};
