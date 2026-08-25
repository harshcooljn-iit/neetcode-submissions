class Solution {
public:
    vector<vector<int> > subsetss;
    vector<int> subset;
    void gen(int i, vector<int>& a){
        if (i==a.size()){
            subsetss.push_back(subset);
            return;
        }
        // don't take i-th element
        gen(i+1,a);
        // take i-th element
        subset.push_back(a[i]);
        gen(i+1,a);
        subset.pop_back();
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        gen(0,nums);
        return subsetss;
    }
};
