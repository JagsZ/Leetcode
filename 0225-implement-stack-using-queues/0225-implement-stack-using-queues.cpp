class MyStack {
    queue<int> q;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int val = q.back();
        while(q.size() > 1){
            q2.push(q.front());
            q.pop();
        }
        q.pop();
        queue<int> tmp;
        tmp = q;
        q = q2;
        q2 = tmp;
        return val;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        if(q.size() == 0)
            return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */