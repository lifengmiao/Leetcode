/*
A regular stack already supports the first 3 operations, so we focus on the last two.

For peekMax, we remember the largest value we've seen on the side. For example if we add [2, 1, 5, 3, 9], we'll remember [2, 2, 5, 5, 9]. This works seamlessly with pop operations, and also it's easy to compute: it's just the maximum of the element we are adding and the previous maximum.

For popMax, we know what the current maximum (peekMax) is. We can pop until we find that maximum, then push the popped elements back on the stack.
*/
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        int pre_max = mMaxStack.empty()?x:mMaxStack.top();
        mMaxStack.push(pre_max>x?pre_max:x);
        mStack.push(x);
    }
    
    int pop() {
        mMaxStack.pop();
        int tmp = mStack.top();
        mStack.pop();
        return tmp;
    }
    
    int top() {
        return mStack.top();
    }
    
    int peekMax() {
        return mMaxStack.top();
    }
    
    int popMax() {
        int max_tmp = mMaxStack.top();
        stack<int> buff;
        while(mStack.top()!=max_tmp) {
            buff.push(mStack.top());
            pop(); //need to pop() both stacks
        }
        pop();
        while(!buff.empty()) {
            int tmp = buff.top();
            buff.pop();
            push(tmp);//need to push() both stacks
        }
        return max_tmp;
    }
private:
    stack<int> mStack;
    stack<int> mMaxStack;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
