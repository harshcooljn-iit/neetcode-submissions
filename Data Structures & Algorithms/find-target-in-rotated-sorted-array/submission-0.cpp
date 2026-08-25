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
        return ans;
    }
    int search(vector<int>& nums, int target) {
        // we have 2 arrays 0 to min which is increasing 
        // and min to n which is also increasing
        int n = nums.size();
        int x = findMin(nums);
        int lo=0,hi=x-1;
        int ans = -1;
        while (lo<=hi){
            int mid = (lo+hi)>>1;
            if (nums[mid]<target){
                lo=mid+1;
            }
            else if (nums[mid]==target){
                return mid;
            }
            else{
                hi=mid-1;
            }
        }
        lo=x,hi=n-1;
        while (lo<=hi){
            int mid = (lo+hi)>>1;
            if (nums[mid]<target){
                lo=mid+1;
            }
            else if (nums[mid]==target){
                return mid;
            }
            else{
                hi=mid-1;
            }
        }
        return -1;
    }
};
