using ll = int;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (ll i=0;i<numbers.size();i++){
            ll b = lower_bound(numbers.begin(),numbers.end(),target-numbers[i]) - numbers.begin();
            if (b<numbers.size() && b>=0 && b!=i && numbers[i]+numbers[b]==target) return {i+1,b+1};
        }
    }
};
