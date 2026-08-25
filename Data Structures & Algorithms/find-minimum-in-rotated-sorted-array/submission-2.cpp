class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int lo = 0,hi=n-1;
        int ans = 0;
        while (lo<=hi){
            int mid = (lo+hi)/2;
            if (nums[mid]<nums[0]){
                ans = mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return nums[ans];
    }
};
