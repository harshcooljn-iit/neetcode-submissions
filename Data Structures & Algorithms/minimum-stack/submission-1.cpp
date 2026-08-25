class MinStack {
private:
    vector<int> stk;
    multiset<int> st;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push_back(val);
        st.insert(val);
    }
    
    void pop() {
        st.erase(st.find(stk.back()));
        stk.pop_back();
    }
    
    int top() {
        return stk.back();
    }
    
    int getMin() {
        return *st.begin();
    }
};
