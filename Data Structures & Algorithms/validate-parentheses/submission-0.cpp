class Solution {
public:
    bool isValid(const std::string& s) {
        std::stack<char> st;

        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
                continue;
            }

            if (st.empty()) {
                return false;
            }

            char top = st.top();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }

            st.pop();
        }

        return st.empty();
    }
};
