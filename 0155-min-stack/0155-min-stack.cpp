#include<stack>
class MinStack {

private:
stack<int> mainStack;
stack<int> minStack;

public:
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        int newMin = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(newMin);
    }
    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {


        return minStack.top();
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