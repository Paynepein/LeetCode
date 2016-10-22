class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        vec.push_back(x);
        if (minVec.size() == 0) minVec.push_back(x);
        else minVec.push_back(min(minVec.back(), x));
    }
    
    void pop() {
        vec.pop_back();
        minVec.pop_back();
    }
    
    int top() {
        return vec.back();
    }
    
    int getMin() {
        return minVec.back();
    }
private:
    vector<int> vec;
    vector<int> minVec;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */