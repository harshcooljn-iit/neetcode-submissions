class MedianFinder {
public:

    priority_queue<int> maxheap; // store smaller half of elements
    priority_queue<int,vector<int>,greater<int> > minheap; // store bigger half of elements
    int n; // number of elements
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if (n == 0 || maxheap.top() >= num){
            maxheap.push(num);
            if (maxheap.size() > minheap.size() + 1){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        }
        else{
            minheap.push(num);
            if (minheap.size() > maxheap.size()){
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
        n++;
    }
    
    double findMedian() {
        if (n&1){
            return maxheap.top();
        }
        else{
            double median = (maxheap.top() + minheap.top())/2.0;
            return median;
        }
    }
};
