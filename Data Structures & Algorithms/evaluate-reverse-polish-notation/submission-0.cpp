class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                st.push(stoi(token));
            } else {
                int right = st.top();
                st.pop();

                int left = st.top();
                st.pop();

                if (token == "+")
                    st.push(left + right);
                else if (token == "-")
                    st.push(left - right);
                else if (token == "*")
                    st.push(left * right);
                else
                    st.push(left / right);
            }
        }

        return st.top();
    }
};