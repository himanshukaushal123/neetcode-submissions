class Solution {
public:  
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> ans(n, 0);
        stack<pair<int, int>> st; //The stack stores candidate future days that could be the next warmer day.

        // Stack stores {temperature, index}
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top().first <= temperatures[i]) {
                st.pop();
            }

            if (!st.empty()) {
                ans[i] = st.top().second - i;
            }

            st.push({temperatures[i], i});
        }

        return ans;
    }
};
