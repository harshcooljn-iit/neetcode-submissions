class FreqStack {
public:
    unordered_map<int,int> freq;
    vector<stack<int> > stk;
    FreqStack() {
        stk.push_back(stack<int>());
    }
    
    void push(int val) {
        freq[val]++;
        if (freq[val] > stk.size()){
            stk.push_back(stack<int>());
        }
        stk[freq[val]-1].push(val);
    }
    
    int pop() {
        int ans = stk.back().top();
        stk.back().pop();
        if (stk.back().empty()) stk.pop_back();
        freq[ans]--;
        if (freq[ans] == 0) freq.erase(ans);
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */