class Solution {
public:
    set<vector<int> > ans;
    vector<int> combination;
    void func(int i, int sum_left, vector<int>& a){
        if (sum_left==0){
            auto comb = combination;
            sort(comb.begin(),comb.end());
            ans.insert(comb);
            return;
        }

        if (i==a.size()){
            return;
        }

        func(i+1, sum_left, a);
        if (a[i]<=sum_left){
            combination.push_back(a[i]);
            func(i,sum_left-a[i], a);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& a, int target) {
        func(0,target,a);
        vector<vector<int>> vec;
        for (auto& v: ans){
            vec.push_back(v);
        }
        return vec;
    }
};
