class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto& e: stones){
            pq.push(e);
        }
        while (!pq.empty()){
            int a = pq.top();
            pq.pop();
            if (pq.empty()) return a;
            int b = pq.top();
            pq.pop();
            pq.push(a-b);
        }
    }
};
