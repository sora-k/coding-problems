//started 1/31/17 8:10AM - 10:00 AM (not done)
//                9:00PM - 9:59 PM (done)
// TODO: Read solution
//       Redo->Took too long!!

// One queue solution O(N) - push (best solution)
class MyStack {
    public:
        MyStack() {
        }
        void push(int x) {
            
            int size = q_.size();

            q_.push(x);

            while(size > 0){
                int val = q_.front();    
                q_.pop();
                q_.push(val);
                size--;
            }
        }
        int pop() {
            
            int result = q_.front();
            q_.pop();
            
            return result;
        }
        int top() {
            return q_.front();
        }
        bool empty() {
            return q_.empty();
        }
    private:
        std::queue<int> q_;
};
// Two queue solution O(N) - push (cleaner, don't have to keep track of top)
/*
class MyStack {
    public:
        MyStack() {
            if(q_ == 0){
                q_ = new std::queue<int>;
            }
        }
        ~MyStack(){
            if(q_ != 0){
                delete q_;
                q_ = 0;
            }
        }
        void push(int x) {
            
            std::queue<int> *tmp_q = new std::queue<int>;

            tmp_q->push(x);
            while(q_->empty() == false){
                int cur_val = q_->front();
                q_->pop();
                tmp_q->push(cur_val);
            }

            delete q_;
            q_ = tmp_q;
        }
        int pop() {
            
            int result = q_->front();
            q_->pop();
            
            return result;
        }
        int top() {
            return q_->front();
        }
        bool empty() {
            return q_->empty();
        }
    private:
        std::queue<int> *q_ = 0;
};
*/
// Two queue solution O(N) - pop
/*
class MyStack {
    public:
        MyStack() {
            if(q_ == 0){
                q_ = new std::queue<int>;
            }
        }
        ~MyStack(){
            if(q_ != 0){
                delete q_;
                q_ = 0;
            }
        }
        void push(int x) {
            top_ = x;
            q_->push(x);
        }
        int pop() {
            
            int result;
            
            std::queue<int> *tmp_q = new std::queue<int>;            
            while(q_->empty() == false){
                int cur_val = q_->front();
                q_->pop();

                if(q_->empty() == true){
                    result = cur_val;                    
                }else{
                    top_ = cur_val;
                    tmp_q->push(cur_val);
                }   
            }
            delete q_;
            q_ = tmp_q;
            
            return result;
        }
        int top() {
            return top_;
        }
        bool empty() {
            return q_->empty();
        }
    private:
        std::queue<int> *q_ = 0;
        int top_;
};
*/
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

/*
["MyStack","push","push","push","top","pop","top","pop","top","empty","pop","empty"]
[[],[1],[2],[3],[],[],[],[],[],[],[],[]]
["MyStack","push","push","pop","top"]
[[],[1],[2],[],[]]
["MyStack","push","pop","empty"]
[[],[1],[],[]]
*/