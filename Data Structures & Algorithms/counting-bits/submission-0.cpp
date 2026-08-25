class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        int two = 1;
        for (int i=1;i<=n;i++){
            if (2*two<=i){
                two*=2;
            }
            ans.push_back(1+ans[i-two]);
        }
        return ans;
    }
};
