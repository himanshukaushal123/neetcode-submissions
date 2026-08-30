class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> ump;
        int max_con = 0;

        for (int num : nums) {
            // Ignore duplicates
            if (ump.find(num) != ump.end())
                continue;

            // Length of sequence ending just before num
            int left = 0;
            if (ump.find(num - 1) != ump.end())
                left = ump[num - 1];

            // Length of sequence starting just after num
            int right = 0;
            if (ump.find(num + 1) != ump.end())
                right = ump[num + 1];

            // New merged sequence length
            int length = left + 1 + right;

            ump[num] = length;

            // Update the boundaries of the sequence
            if (left > 0)
                ump[num - left] = length;

            if (right > 0)
                ump[num + right] = length;

            max_con = max(max_con, length);
        }

        return max_con;
    }
};
