/*
    Min Stack
    ----------
    Supports the following operations in O(1) time:
    - push(x)
    - pop()
    - top()
    - getMin()

    Approach:
    Store a pair in the stack:
    - first  -> actual value
    - second -> minimum element in the stack up to this position

    Time Complexity:
    push()   : O(1)
    pop()    : O(1)
    top()    : O(1)
    getMin() : O(1)

    Space Complexity:
    O(n)
*/

class MinStack {
private:
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
        } else {
            st.push({value, min(value, st.top().second)});
        }
    }

    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};