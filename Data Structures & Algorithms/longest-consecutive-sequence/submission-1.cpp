class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int max_con = 0;

        for (int num : st) {
            // Start of a sequence
            if (st.find(num - 1) == st.end()) {
                int current = num;
                int length = 1;

                while (st.find(current + 1) != st.end()) {
                    current++;
                    length++;
                }

                max_con = max(max_con, length);
            }
        }

        return max_con;
    }
};
