class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        k = n - k;
        srand(time(0));
        function<int(int,int)> quickSelect = [&](int l, int r){
            int idx = l + (rand() % (r-l+1));
            // cout << idx << endl;
            swap(nums[idx],nums[r]);
            int pivot = nums[r];
            int p = l; // partition index
            for (int i=l;i<r;i++){
                if (nums[i] <= pivot){
                    swap(nums[i], nums[p]);
                    p += 1;
                }
            }
            swap(nums[p], nums[r]);
            if (p > k){ // this means k-th element lies in the left half
                return quickSelect(l,p-1);
            }
            else if (p < k){ // this means k-th element lies in the right half
                return quickSelect(p+1,r);
            }
            else{
                return nums[p];
            }
        };
        return quickSelect(0,n-1);
    }
};
