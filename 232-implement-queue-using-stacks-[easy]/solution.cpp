//started 2/2/17  9:27PM - 10:08PM (Two stacks - O(2N) - push)


// Two stacks - O(1) push, O(1) Amortized Pop
//            - [stack for push], [stack_invert for pop], update stack_invert when it's empty
//            - store [top_] in the case where stack_invert is empty and stack is not;

using std::stack;

class MyQueue {
public:

    MyQueue() {
    }
    void push(int x) {
        
        top_ = stack_.empty() ? x : top_; 
        stack_.push(x);

    }
    int pop() {

        int result;

        if(stack_invert_.empty() == true){
            while(stack_.empty() == false){
                int val = stack_.top();
                stack_.pop();
                stack_invert_.push(val);
            }
        }
        result = stack_invert_.top();
        stack_invert_.pop();

        return result;            
    }
    int peek() {
        
        int result;

        result = stack_invert_.empty() ? top_ : stack_invert_.top();

        return result;

    }
    bool empty() {
        
        return stack_.empty() && stack_invert_.empty();

    }
private:
    stack<int> stack_, stack_invert_;
    int top_;
};


// Two stacks - O(2N) - push
/*
using std::stack;

class MyQueue {
public:

    MyQueue() {
    }
    void push(int x) {
        
        stack<int> tmp;
        int val;

        while(stack_.empty() == false){
            val = stack_.top();
            stack_.pop();
            tmp.push(val);
        }

        stack_.push(x);
        while(tmp.empty() == false){
            val = tmp.top();
            tmp.pop();
            stack_.push(val);
        }
    }
    int pop() {

        int result = stack_.top();
        stack_.pop();

        return result;            
    }
    int peek() {
        
        return stack_.top();

    }
    bool empty() {
        
        return stack_.empty();

    }
private:
    stack<int> stack_;
};
*/
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
/*
["MyQueue","empty"]
[[],[]]
["MyQueue","empty","push","push","push","peek","peek","peek","pop","pop","peek"]
[[],[],[1],[2],[3],[],[],[],[],[],[]]
*/