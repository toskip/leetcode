//只用一个栈实现
//用两个栈实现的很容易想到所以不写了
class MinStack {
public:
    /** initialize your data structure here. */
    int min;
    stack<int> mystack;
    MinStack() {
    }
    
    void push(int x) {
        if(mystack.empty() || x<min) min = x;
        mystack.push(min);
        mystack.push(x);
    }
    
    void pop() {
        mystack.pop();
        mystack.pop();
        if(!mystack.empty())
        {
            int temp = mystack.top();
            mystack.pop();
            min = mystack.top();
            mystack.push(temp);
        }
    }
    
    int top() {
        return mystack.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
