using ll = int;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ll n = numbers.size();
        ll l=0,r=n-1;
        ll k = target;
        while (l<r){
            if (numbers[l]+numbers[r]<k){
                l++;
            }
            else if (numbers[l]+numbers[r]>k){
                r--;
            }
            else {
                return {l+1,r+1};
            }
        }
    }
};
