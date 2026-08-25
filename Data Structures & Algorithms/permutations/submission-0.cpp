class Solution {
public:
    vector<vector<int> > ans;
    vector<int> marked;
    vector<int> permutation;
    void func(int sz, vector<int>& a){
        if (sz==0){
            ans.push_back(permutation);
            return;
        }

        for (int i=0;i<a.size();i++){
            if (!marked[i]){
                permutation.push_back(a[i]);
                marked[i] = 1;
                func(sz-1,a);
                permutation.pop_back();
                marked[i] = 0;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& a) {
        marked = vector<int>(a.size());
        func(a.size(), a);
        return ans;
    }
};
