class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        while (!mystack1.empty()) {
            mystack2.push(mystack1.top());
            mystack1.pop();
        }
        mystack1.push(x);
        while (!mystack2.empty()) {
            mystack1.push(mystack2.top());
            mystack2.pop();
        }
    }

    // Removes the element from in front of queue.
    void pop(void) {
        mystack1.pop();
    }

    // Get the front element.
    int peek(void) {
        return mystack1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return mystack1.empty();
    }

private:
    stack<int> mystack1;
    stack<int> mystack2;
};