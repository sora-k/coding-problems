//started 4/22/17 9:00PM - 9:50PM

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack.push_back(x);

        if(min_stack.size() > 0 && min_stack.back() >= x)
            min_stack.push_back(x);
        if(min_stack.size() == 0)
            min_stack.push_back(x);
    }
    
    void pop() {
        if(stack.size() > 0){
            if(stack.back() == min_stack.back())
                min_stack.pop_back();
            stack.pop_back();
        }
    }
    
    int top() {
        if(stack.size() > 0)
            return stack.back();
        else
            return -1;
    }
    
    int getMin() {
        if(min_stack.size() > 0)
            return min_stack.back();
        else
            return -1;
    }
private:
    vector<int> stack;
    vector<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */