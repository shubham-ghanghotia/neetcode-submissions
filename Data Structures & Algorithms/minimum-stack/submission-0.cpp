class MinStack {
    vector<int> st;
    vector<int> minSt;

public:
    MinStack() {
        
    }
    
    void push(int val) {
       st.push_back(val);
       if(minSt.empty()){
            minSt.push_back(val);
       } else {
            minSt.push_back(min(minSt[minSt.size() - 1], val));
       }
    } 
    
    void pop() {
        st.pop_back();
        minSt.pop_back();
    }
    
    int top() {
        return st[st.size() - 1];
    }
    
    int getMin() {
        return minSt[minSt.size() - 1];
    }
};
