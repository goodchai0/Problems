class MyQueue {
public:
    stack<int>s1;
    stack<int>s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int n=s1.size();
        while(n--){
            int y=s1.top();
            s1.pop();
            s2.push(y);
        }
        int x=s2.top(); 
        s2.pop();
        n=s2.size();
        while(n--){
            int y=s2.top();
            s2.pop();
            s1.push(y);
        }
        return x;
    }
    
    int peek() {
        int n=s1.size();
        while(n--){
            int y=s1.top();
            s1.pop();
            s2.push(y);
        }
        int x=s2.top(); 
        n=s2.size();
        while(n--){
            int y=s2.top();
            s2.pop();
            s1.push(y);
        }
        return x;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */