class MinStack {
public:
    stack<long long> st;
    long long mini;
    MinStack() { mini = INT_MAX; }
    void push(int val) {
        long long ele = (long long)val;
        if (st.size() == 0) {
            st.push(ele);
            mini = ele;
        }
        else if(ele>=mini){
            st.push(ele);
        }
        else{
            st.push(2*ele-mini);
            mini = ele;
        }
    }
    void pop() {
        long long oldmin;
        if(st.top()<mini){
            oldmin = 2*mini-st.top();
            mini = oldmin;
        }
        st.pop();
    }

    int top() {
        if(st.top()<mini){
            return (int)mini;
        }
        else{
            return st.top();
        }

    }

    int getMin() {
        return (int)mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */