class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n-1;
        int ans;
        while (lo<=hi){
            int mid = (lo+hi)>>1;
            if (nums[mid]<=target){
                ans = mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        if (nums[ans]==target) return ans;
        else return -1;
    }
};
