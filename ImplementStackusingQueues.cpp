class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        int len = queueHelper.size();
        queueHelper.push(x);
        for (int i = 0; i < len; ++i) {
            queueHelper.push(queueHelper.front());
            queueHelper.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        queueHelper.pop();
    }

    // Get the top element.
    int top() {
        return queueHelper.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return queueHelper.empty();
    }
private:
    queue<int> queueHelper;
};