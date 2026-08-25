class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (auto& e: nums){
            if (pq.size() < k){
                pq.push(-e);
            }
            else{
                if (e > -pq.top()){
                    pq.pop();
                    pq.push(-e);
                }
            }
        }
        return -pq.top();
    }
};
