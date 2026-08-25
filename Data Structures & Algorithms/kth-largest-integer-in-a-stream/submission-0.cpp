class KthLargest {
public:
    priority_queue<int> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        int n = nums.size();
        for (int i=0;i<n;i++){
            if (pq.size() < k){
                pq.push(-nums[i]);
            }
            else{
                if (nums[i] > -pq.top()){
                    pq.pop();
                    pq.push(-nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if (pq.size() < k){
                pq.push(-val);
        }
        else{
            if (val > -pq.top()){
                pq.pop();
                pq.push(-val);
            }
        }
        return -pq.top();
    }
};
