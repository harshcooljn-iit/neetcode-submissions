class FreqStack {
public:
    unordered_map<int,int> freq;
    unordered_map<int,vector<int> > pos;
    set<tuple<int,int,int> > st;
    int top = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        top++;
        if (freq.find(val) != freq.end()){
            st.erase({freq[val], pos[val].back(), val});
        }
        freq[val]++;
        pos[val].push_back(top);
        st.insert({freq[val], pos[val].back(), val});
    }
    
    int pop() {
        if (st.empty()) return -1;
        auto [f,t,val] = *st.rbegin();
        st.erase(--st.end());
        freq[val]--;
        pos[val].pop_back();
        if (freq[val] > 0){
            st.insert({freq[val],pos[val].back(),val});
        }
        else{
            freq.erase(val);
            pos.erase(val);
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */