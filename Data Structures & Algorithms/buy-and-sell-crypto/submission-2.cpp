class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0 , r = 1;
        int ans = 0;
        while (r < n){
            if (prices[r] < prices[l]){
                l=r;
            }
            else{
                ans = max(ans, prices[r]-prices[l]);
            }
            r++;
        }
        return ans;
    }
};
