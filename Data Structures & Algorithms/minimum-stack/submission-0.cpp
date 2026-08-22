#include <stack>
#include <utility>
#include <algorithm>

class MinStack {
private:
    std::stack<std::pair<int, int>> st;

public:
    MinStack() = default;

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
            return;
        }

        int currentMin = std::min(val, st.top().second);
        st.push({val, currentMin});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};